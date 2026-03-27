*This project has been created as part of the 42 curriculum by [your_login].*

# miniRT: My First Ray Tracer

## 📝 Description

**miniRT** is a minimalist ray tracing engine developed in **C**. The goal of this project is to render 3D scenes by simulating the physical behavior of light. By calculating intersections between rays and geometric objects, the engine generates images featuring realistic lighting, shadows, and perspectives.

### 🚀 Features

* **Window Management:** Smooth window handling, including clean exit (cross icon or `ESC`) using the **MiniLibX**.
* **Geometric Primitives:**
    * **Plane:** Infinite surfaces with specific orientations.
    * **Sphere:** Perfect curved surfaces defined by a center and diameter.
    * **Cylinder:** Finite objects with a radius and height.
* **Lighting & Color:**
    * **Ambient Lighting:** Global light to ensure no part of the scene is pitch black.
    * **Diffuse Reflection:** Light intensity based on the angle of incidence (Lambertian).
    * **Specular Reflection:** Highlights based on the Phong reflection model.
    * **Shadows:** Objects accurately block light sources.
* **Camera:** Fully adjustable view point, orientation, and Field of View (FOV).
* **Scene Parsing:** Reads `.rt` files to define objects, lights, and camera settings.

## 🛠 Technical Choices

The engine follows a **Ray Casting** approach where a ray is fired from the camera for every pixel. We implemented a linear algebra library to handle vector operations (addition, normalization, dot product, cross product). The core logic solves quadratic equations to find the closest intersection point $t$ for spheres and cylinders. To maintain the **42 Norm**, the codebase is strictly modularized, separating the parser, the math engine, and the image renderer.

## 💻 Instructions

### Compilation

To compile the project and generate the `miniRT` executable, run:

```bash
make