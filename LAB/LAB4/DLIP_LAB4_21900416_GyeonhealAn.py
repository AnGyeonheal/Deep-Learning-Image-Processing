# * DLIP_LAB4_CNN Object Detection 1_Parking Management System
# * author: Gyeonheal An
# * Date: 2024-06-07

import logging
from ultralytics import YOLO
import cv2 as cv

def main():
    setup_logging()
    video_path = 'DLIP_parking_test_video.avi'
    cap = load_video(video_path)
    model = initialize_model('yolov8l.pt')
    space_points = [(83, 366), (202, 367), (297, 363), (404, 364), (499, 361), (588, 358), (684, 357),
                    (785, 357), (877, 357), (971, 355), (1063, 359), (1160, 360), (1249, 354)]  # Parking Space의 중앙점
    roi_coords = (0, 240, 1280, 160)  # ROI points
    frame_index = 0

    # fourcc = cv.VideoWriter_fourcc(*'XVID')
    # out = cv.VideoWriter('output_video.avi', fourcc, 20.0, (int(cap.get(cv.CAP_PROP_FRAME_WIDTH)), int(cap.get(cv.CAP_PROP_FRAME_HEIGHT))))

    with open('counting_result.txt', 'w') as f:
        while cap.isOpened():
            ret, frame = cap.read()
            if not ret:
                print("Cannot find video file")
                break

            car_count, occupied_points, roi = detect_and_count_cars(frame, model, space_points, roi_coords)
            space_count = label_empty_spaces(frame, space_points, occupied_points)
            display_counts(frame, car_count, space_count)

            # Record the number of cars per frame in a text file.
            f.write(f'{frame_index},{car_count}\n')
            frame_index += 1
            x, y, w, h = roi_coords
            frame[y:y + h, x:x + w] = roi
            cv.imshow('YOLOv8 Detection', frame)

            # out.write(frame)

            if cv.waitKey(1) & 0xFF == ord('q'):
                break
    cap.release()
    # out.release()
    cv.destroyAllWindows()

def setup_logging():
    logging.getLogger('ultralytics').setLevel(logging.CRITICAL)  # Do not output logs to the console.

def load_video(video_path):
    return cv.VideoCapture(video_path)

def initialize_model(model_path='yolov8l.pt'):
    return YOLO(model_path)

def detect_and_count_cars(frame, model, space_points, roi_coords):
    x, y, w, h = roi_coords
    roi = frame[y:y + h, x:x + w]  # ROI
    results = model(roi)  # YOLOv8 model
    car_count = 0
    occupied_points = set()

    for result in results:
        for box in result.boxes:
            x1, y1, x2, y2 = map(int, box.xyxy[0])
            confidence = box.conf[0]  # Initializing
            class_id = int(box.cls[0])

            if class_id == 2:  # Consider only car class
                label = f'{model.names[class_id]} {confidence:.2f}'
                cv.rectangle(roi, (x1, y1), (x2, y2), (0, 255, 0), 2)
                cv.putText(roi, label, (x1, y1 - 10), cv.FONT_HERSHEY_SIMPLEX, 0.9, (0, 255, 0), 2)

                for point in space_points:  # Check if the center point of Parking Space is inside the car Boundary Box
                    px, py = point
                    if x1 < px < x2 and y1 < py < y2 + 240:
                        car_count += 1
                        occupied_points.add(point)  # Save the parking space center points which is already occupied
                        break

    return car_count, occupied_points, roi

def label_empty_spaces(frame, space_points, occupied_points):
    space_count = 0
    for point in space_points:
        if point not in occupied_points:  # If the parking space is empty
            px, py = point
            space_count += 1
            cv.putText(frame, "EMPTY", (px - 20, py), cv.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 255), 2)
    return space_count

def display_counts(frame, car_count, space_count):
    count_label = f'Car Count: {car_count}'
    space_label = f'Space Count: {space_count}'

    cv.putText(frame, count_label, (10, 50), cv.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 0), 2)
    cv.putText(frame, space_label, (10, 75), cv.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 0), 2)

if __name__ == "__main__":
    main()
