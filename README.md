<h2>Description</h2> This project is a 2D curve modeling tool developed in C++ that allows users to render and manipulate Bezier and B-Spline curves. It demonstrates computational geometry principles and includes interactive features for real-time editing of control points. The tool provides an intuitive way to visualize curve structures and is useful for understanding curve modeling techniques. <br /> <h2>Languages and Utilities Used</h2> - **C++** - **OpenGL** <h2>Environments Used</h2> - **Visual Studio 2022** - **Windows 10** (21H2) <h2>Program Walk-through:</h2> <p align="center"> Launch the utility: <br/> <img src="examples/launch_screen.png" height="80%" width="80%" alt="Launch Screen" /> <br /> <br /> Add control points to the canvas: <br/> <img src="examples/add_control_points.png" height="80%" width="80%" alt="Adding Control Points" /> <br /> <br /> Render Bezier curve using de Casteljau’s algorithm: <br/> <img src="examples/render_bezier.png" height="80%" width="80%" alt="Bezier Curve" /> <br /> <br /> Render B-Spline curve: <br/> <img src="examples/render_b_spline.png" height="80%" width="80%" alt="B-Spline Curve" /> <br /> <br /> Adjust curve detail levels using the "+" and "-" keys: <br/> <img src="examples/adjust_detail.png" height="80%" width="80%" alt="Adjusting Detail Levels" /> <br /> <br /> Interactively drag control points to reshape the curve: <br/> <img src="examples/drag_control_points.png" height="80%" width="80%" alt="Dragging Control Points" /> </p> <h2>Features</h2> - **Bezier Curves**: Rendered using the de Casteljau algorithm with real-time updates based on control point positions. - **B-Spline Curves**: Computed using matrix-based formulations for cubic splines. - **Interactive Editing**: Add, delete, and drag control points dynamically to reshape the curves. - **Detail Level Adjustment**: Modify the smoothness and granularity of curves interactively using keyboard inputs. <h2>How to Use</h2> 1. Clone the repository: ```bash git clone https://github.com/yourusername/Bezier-Spline-Curve-Modeler.git cd Bezier-Spline-Curve-Modeler ```
Open the solution file (hw-curves.sln) in Visual Studio 2022.

Build and run the project.

Program controls:

Left-click: Add control points.
Right-click: Delete control points.
Drag: Move control points interactively.
Number Keys:
0: Switch to straight-line mode.
1: Render Bezier curves.
2: Render B-Spline curves.
+ and -: Adjust the detail level of curves.
<h2>Example Outputs</h2> Here are some outputs generated using the tool: <p align="center"> <img src="examples/sample_output_bezier.png" width="80%" alt="Sample Bezier Output"> <br /> Bezier Curve Rendered with De Casteljau Algorithm </p> <p align="center"> <img src="examples/sample_output_bspline.png" width="80%" alt="Sample B-Spline Output"> <br /> B-Spline Curve Rendered with Uniform Cubic Splines </p> <h2>Future Extensions</h2> - Extend functionality to support 3D modeling (e.g., surfaces of revolution derived from 2D curves). - Add support for additional spline types and higher-order Bezier curves. - Enhance the interface to allow real-time parameter adjustments. 
