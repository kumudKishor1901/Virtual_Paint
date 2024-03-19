# Virtual Paint Project

## Overview
This is a virtual paint project implemented in C++ using the OpenCV library. The project allows users to draw on a virtual canvas using predefined colors detected from a live video stream. It utilizes color detection techniques and contour analysis to identify specific colors and draw corresponding shapes on the canvas.

## Dependencies
- OpenCV 4.x
- C++ compiler supporting C++11 or later

## Installation and Setup
1. **Install OpenCV**: Ensure you have OpenCV 4.x installed on your system. You can follow the official [OpenCV installation guide](https://docs.opencv.org/master/d7/d9f/tutorial_linux_install.html) for installation instructions.

2. **Clone the Repository**: Clone this repository to your local machine using the following command:
    ```
    git clone <repository_url>
    ```

3. **Build the Project**: Use your preferred C++ compiler to build the project. Make sure to link against the OpenCV libraries. For example, you can use g++:
    ```
    g++ -o virtual_paint virtual_paint.cpp `pkg-config --cflags --libs opencv4`
    ```

## Usage
1. **Connect Webcam**: Ensure your webcam is connected to the system.

2. **Run the Program**: Execute the compiled binary:
    ```
    ./virtual_paint
    ```

3. **Painting**: Hold an object with one of the predefined colors in front of the webcam. The program will detect the color and draw corresponding shapes on the virtual canvas.

4. **Quit**: Press `Esc` key to quit the program.

## Customization
- **Colors**: You can customize the colors by modifying the `mycolors` and `colors` vectors in the code. Each color range is defined as `{Hmin, Smin, Vmin, Hmax, Smax, Vmax}` in the HSV color space.
- **Canvas Size**: Adjust the size of the canvas by modifying the dimensions of the `img` Mat object in the code.

## Contributions
Contributions to this project are welcome. Feel free to fork the repository, make changes, and submit pull requests.

## Acknowledgments
- This project was inspired by the need for a simple virtual paint application using computer vision techniques.
- Thanks to the OpenCV community for providing powerful tools for image processing and computer vision.
