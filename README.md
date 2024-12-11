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

## 🎥 **Program Walk-through**

Below is an outline of the core functionalities of the tool. Each step highlights how users can interact with the system to explore and manipulate curves dynamically.

---

### **1. Launch the Utility**
Start by launching the application to access the application interface.  
<div align="center">
  <img src="https://github.com/user-attachments/assets/b069be93-7c9e-4bd2-a442-9d0422a91acf" alt="Application Launch Screen" width="45%" />
</div>

---

### **2. Add & Delete Control Points**
💡 **Tip:** Use the **left mouse button** to add control points on the canvas. These points form the foundation of your curve modeling. To remove a control point, simply use the **right mouse button**.

<div align="center">
  <img src="examples/Add_Delete_Control_Points.gif" alt="Add Control Points" width="45%" />
</div>

---

### **3. Render Bezier Curves** and **4. Render B-Spline Curves**
💡 **Key Features:** 
- **Bezier Curves**: Render smooth and precise curves using **de Casteljau’s algorithm**.
- **B-Spline Curves**: Visualize smooth, continuous curves with **cubic spline formulations**.

<div align="center">
  <img src="examples/Bezier_Curve_Mode.gif" alt="Bezier Curve Mode" width="45%" />
  <img src="examples/BSpline_Curve_Mode.gif" alt="B-Spline Curve Mode" width="45%" />
</div>

---

### **5. Adjust Curve Detail Levels**
💡 **Customize Your Curve:** Use the **`+` and `-` keys** to refine the smoothness and granularity of the curves.

<div align="center">
  <img src="examples/Bezier_Curve_LOD.gif" alt="Bezier Curve LOD" width="45%" />
  <img src="examples/BSpline_Curve_LOD.gif" alt="B-Spline Curve LOD" width="45%" />
</div>

---

### **6. Drag and Reshape Control Points**
💡 **Interactive Editing:** Dynamically reshape curves by dragging control points to new positions. This feature provides **real-time visual updates** for precise modeling.

<div align="center">
  <img src="examples/Drag_&_Reshape.gif" alt="Drag & Reshape Control Points" width="45%" />
</div>

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

## 🛠️ Technologies at a Glance

- **Programming Language**: C++  
- **Graphics Library**: OpenGL  

---

## 💻 Development Environment

- **IDE**: Visual Studio 2022  
- **OS**: Windows 10 (21H2)  

---


