# * DLIP_LAB3_Tension Detection of Rolling Metal Sheet
# * author: Gyeonheal An
# * Date: 2024-05-07

import numpy as np
import cv2 as cv

# 이미지 로드
img = cv.imread("Challenging_Dataset/LV1.png")

# BGR to GrayScale
src = cv.cvtColor(img, cv.COLOR_BGR2GRAY)

# 1. High Intensity filter out
threshold_value = 50
src[src >= threshold_value] = 0

# 2. ROI setting
x, y, w, h = 0, 400, 500, 630
roi = src[y:y + h, x:x + w]

# 3. Filtering
for i in range(3):
    blur = cv.medianBlur(roi, 15)
blur = cv.blur(blur, (5, 5))

# 4. Canny Edge Detection
canny = cv.Canny(blur, 0, 30)
y_coords, x_coords = np.where(canny == 255)

# 5. Polyfit (2nd Order)
coefficients = np.polyfit(x_coords, y_coords, 2)
polynomial = np.poly1d(coefficients)
y_fit = polynomial(x_coords)

# 6. Filtering out points that are far away from the Polyfit graph beyond a threshold.
distances = np.abs(y_coords - y_fit)
distance_threshold = 30

x_filtered = []
y_filtered = []
for i in range(len(x_coords)):
    if distances[i] < distance_threshold:
        x_filtered.append(x_coords[i])
        y_filtered.append(y_coords[i])

# Refitting with refined data
coefficients_filtered = np.polyfit(x_filtered, y_filtered, 2)
polynomial_filtered = np.poly1d(coefficients_filtered)

# Drawing a linear regression graph
x_new = np.linspace(min(x_filtered), max(x_filtered), 100)
y_new = polynomial_filtered(x_new) + 400

max_x = 0
max_y = 0
height = img.shape[0]
width = img.shape[1]

for i in range(len(x_new) - 1):
    cv.line(img, (int(x_new[i]), int(y_new[i])), (int(x_new[i + 1]), int(y_new[i + 1])), (255, 255, 255), 2)
    if (max_y < int(y_new[i])):  # Finding the point with the lowest y-value on the graph
        max_y = int(y_new[i])
        max_x = int(x_new[i])
cv.circle(img, (max_x, max_y), 10, (0, 0, 0), -1)
cv.putText(img, f"Score: {height - max_y}", (max_x, max_y - 75), cv.FONT_HERSHEY_SIMPLEX, 1.0, (255, 255, 255), thickness=3,
           lineType=cv.LINE_AA)

cv.line(img, (0, height - 250), (img.shape[1], height - 250), (255, 0, 0), 2)
cv.line(img, (0, height - 120), (img.shape[1], height - 120), (0, 255, 0), 2)

if max_y > height - 120:
    cv.putText(img, "LV.3", (max_x, max_y - 25), cv.FONT_HERSHEY_SIMPLEX, 1.0, color=(255, 255, 255), thickness=3,
               lineType=cv.LINE_AA)
elif max_y < height - 120 and max_y > height - 250:
    cv.putText(img, "LV.2", (max_x, max_y - 25), cv.FONT_HERSHEY_SIMPLEX, 1.0, color=(255, 255, 255), thickness=3,
               lineType=cv.LINE_AA)
elif max_y < height - 250:
    cv.putText(img, "LV.1", (max_x, max_y - 25), cv.FONT_HERSHEY_SIMPLEX, 1.0, color=(255, 255, 255), thickness=3,
               lineType=cv.LINE_AA)

img = cv.resize(img, (img.shape[1]//2, img.shape[0]//2))
cv.imshow("Regression Image", img)

# cv.imshow("Regression Image", img)
cv.waitKey(0)
