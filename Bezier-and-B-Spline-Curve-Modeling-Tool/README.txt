Curve Modeling and Visualization Framework

Overview
This project provides an interactive tool for creating and visualizing Bezier and B-Spline curves. It uses modern OpenGL and is designed for Visual Studio. The project allows users to dynamically manipulate control points and render curves in real time.

Folder Structure
- Bezier-and-B-Spline-Curve-Modeling-Tool.sln: Solution file to open the project in Visual Studio.
- Bezier-and-B-Spline-Curve-Modeling-Tool Folder: Contains source code files for the project.
- packages Folder: Manages dependencies and libraries used in the project.
- README: This file with instructions to run the project.

How to Run

1. Open the Solution File
   - Open `Bezier-and-B-Spline-Curve-Modeling-Tool.sln` in Visual Studio (2012 or newer).
   - If prompted to upgrade the project files, click OK.

2. Build the Project
   - Press Ctrl+Shift+B or select Build Solution from the Build menu.
   - Ensure the build completes successfully without errors.

3. Run the Program
   - Press F5 or select Start Debugging from the Debug menu.
   - The application window will open, allowing you to create and manipulate curves.

***Must Select Mode Using Number Key First***

Number Keys:
	0: Switch to straight-line mode.
	1: Render Bezier curves.
	2: Render B-Spline curves.
	+ and -: Adjust the detail level of curves.


Program Controls
	Left-click: Add control points.
	Right-click: Delete control points.
	Drag: Move control points interactively.
	

Troubleshooting

- Missing Libraries:
  - Open the NuGet Package Manager (under Tools > NuGet Package Manager > Manage NuGet Packages for Solution).
  - Install any missing libraries such as GLEW or GLUT by searching for them under the Browse tab and clicking Install.

- Shader Issues:
  - Verify that the `shaders` folder (with `nop.vert.glsl` and `nop.frag.glsl`) exists in the correct location relative to the project.

- Build Tools Errors:
  - If you see errors related to missing build tools, open Project Properties and update the build tools version to match your Visual Studio installation.

Features
- Mouse Interaction: Add, modify, or delete control points to shape your curves.
- Real-Time Updates: Instantly see changes reflected on the curves.
- Detail Control: Adjust the level of detail for rendered curves dynamically.

Explore and experiment with curve modeling using this intuitive framework!


