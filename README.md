# Bezier and B-Spline Curve Modeling Tool  

Welcome to the **Bezier and B-Spline Curve Modeling Tool** — a fusion of advanced mathematics and cutting-edge computational geometry that brings curves to life in real-time! Whether you're exploring the art of curve modeling or solving practical design challenges, this tool is crafted for innovators like you.

---

## ✨ Project Highlights

**Why This Stands Out:**  
This 2D modeling tool, developed in **C++**, lets users intuitively render and manipulate **Bezier** and **B-Spline** curves with interactive features for real-time editing. It’s not just a tool — it’s a window into the beauty of mathematical structures and their real-world applications.

- **Dynamic Visualization**: Seamlessly adjust curves and watch them transform before your eyes.  
- **Mathematical Foundations**: Powered by **de Casteljau's algorithm** and matrix formulations for cubic splines.  
- **User-Centric Design**: Built for creatives, designers, and mathematicians alike.

---

## 🛠️ Technologies at a Glance

- **Programming Language**: C++  
- **Graphics Library**: OpenGL  

---

## 💻 Development Environment

- **IDE**: Visual Studio 2022  
- **OS**: Windows 10 (21H2)  

---

## 🌟 Key Features

1. **Bezier Curves**:  
   Rendered using the **de Casteljau algorithm** with interactive, real-time updates.

2. **B-Spline Curves**:  
   Constructed using matrix-based formulations for precision and smoothness.

3. **Interactive Editing**:  
   Add, delete, and drag control points dynamically to shape your curves.

4. **Granularity Control**:  
   Fine-tune detail levels interactively with keyboard inputs for ultimate customization.

---


## 🧑‍🔬 How to Get Started 

1. **Clone the repository**:
   ```bash
   git clone https://github.com/yourusername/Bezier-Spline-Curve-Modeler.git
   cd Bezier-Spline-Curve-Modeler


### Open and Run the Project

1. Open the solution file (`hw-curves.sln`) in **Visual Studio 2022**.
2. Build and run the project.

### Program Controls

- **Left-click**: Add control points.
- **Right-click**: Delete control points.
- **Drag**: Move control points interactively.
- **Number Keys**:
  - `0`: Switch to straight-line mode.
  - `1`: Render Bezier curves.
  - `2`: Render B-Spline curves.
- **+ and -**: Adjust the detail level of curves.

---

## Program Walk-through  

Below is an outline of the core functionalities of the tool. Each step highlights how users can interact with the system to explore and manipulate curves dynamically.

---

#### 1. Launch the Utility  
Start by launching the application to access the application interface.  
![Application Launch Screen](https://github.com/user-attachments/assets/b069be93-7c9e-4bd2-a442-9d0422a91acf)

---

#### 2. Add & Delete Control Points Using Left/Right mouse button.   
Click on the canvas to add control points. These points form the foundation of your curve modeling.  
![Add Control Points](examples/Add_Delete_Control_Points.gif)

---

#### 3. Render Bezier Curves  
Use the control points to render smooth, precise Bezier curves via **de Casteljau’s algorithm**.  
![Bezier Curve Mode](examples/Bezier_Curve_Mode.gif)

---

#### 4. Render B-Spline Curves  
Switch to B-Spline mode to visualize and manipulate curves constructed with cubic spline formulations.  
![B-Spline Curve Mode](examples/BSpline_Curve_Mode.gif)

---

#### 5. Adjust Curve Detail Levels  
Refine the smoothness and granularity of your curves by increasing or decreasing detail levels.  

- **Bezier Curve Detail Adjustment**:  
  ![Bezier Curve LOD](examples/Bezier_Curve_LOD.gif)

- **B-Spline Curve Detail Adjustment**:  
  ![B-Spline Curve LOD](examples/BSpline_Curve_LOD.gif)

---

#### 6. Drag and Reshape Control Points  
Interactively reshape curves by dragging control points to new positions.  
![Drag & Reshape Control Points](examples/Drag_&_Reshape.gif)

---


