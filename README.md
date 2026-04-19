*This project has been created as part of the 42 curriculum by glucken and rspinell*

# miniRT: My First Ray Tracer

## 📝 Description

**miniRT** is a minimalist ray tracing engine developed in **C**. The idea of the project is to render an image by calculating distances from the perspective of the viewer till the objects placed in front of them and then render all in a viewport.
The objects are generated according to the distance from the viewport, the color input and the ambient color, as well as the shadows, according to the direction of the light source.

### 🚀 Features

* **Window Management:** using the **MiniLibX** library..
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

The engine follows a **Ray Casting** approach where a ray is fired from the camera for every pixel. We implemented a linear algebra 
to handle vector operations (addition, normalization, vectorial product, scalar product, vector angles, etc..). The core logic solves quadratic equations to find the closest intersection point $t$ for spheres and cylinders.

## 📐 Maths

<details>
<summary><strong>Rayon (dir)</strong></summary>

For each pixel of the screen, we construct a direction vector `dir` in world space from the camera basis (`camera_space`).

We compute the pixel coordinates in the viewport:

$$vpx = \left(\frac{2(x + 0.5)}{W} - 1\right) \cdot \frac{W}{H} \cdot \tan!\left(\frac{fov}{2}\right)$$

$$vpy = \left(1 - \frac{2(y + 0.5)}{H}\right) \cdot \tan!\left(\frac{fov}{2}\right)$$

Then we combine with the camera basis vectors (right = `camera_space.x`, up = `camera_space.y`, forward = `camera_space.z`) :

$$\vec{dir} = vpx \cdot \vec{right} + vpy \cdot \vec{up} + \vec{forward}$$

The ray is then normalized.

</details>

<details>
<summary><strong>Camera basis (camera_space / create_space)</strong></summary>

We construct an orthonormal basis from the camera direction vector (`camera->vector`) :

* `forward` (`camera_space.z`) = `camera->vector` (already normalized from parsing)
* `right` (`camera_space.y`) = `cross_product(forward, up_world)` with `up_world = (0, 1, 0)`
* `up` (`camera_space.x`) = `cross_product(right, forward)`

Special case : if the camera looks straight up or down, we choose another `up_world` to avoid a zero cross product.

</details>

<details>
<summary><strong>Sphere intersection (distance_sphere)</strong></summary>

We substitute the ray equation $P(t) = O + t\vec{d}$ into the Cartesian equation of the sphere :

$$(x - C_x)^2 + (y - C_y)^2 + (z - C_z)^2 = r^2$$

By setting $\vec{oc} = O_{cam} - C_{sphere}$, we obtain a quadratic equation in $t$ :

$$t^2 (\vec{d} \cdot \vec{d}) + 2t (\vec{oc} \cdot \vec{d}) + (\vec{oc} \cdot \vec{oc} - r^2) = 0$$

If the discriminant $\Delta \geq 0$, the ray hits the sphere. We take the smallest $t > 0$.

</details>

<details>
<summary><strong>Plane intersection (distance_plane)</strong></summary>

A plane is defined by a point $C$ and a normal $\vec{n}$. We look for $t$ such that the ray hits the plane :

$$t = \frac{\vec{n} \cdot (C - O)}{\vec{n} \cdot \vec{d}}$$

If the denominator $\vec{n} \cdot \vec{d} \approx 0$, the ray is parallel to the plane → no intersection. We return $t$ only if $t > 0$.

</details>

<details>
<summary><strong>Cylinder intersection (distance_cylinder)</strong></summary>

The cylinder is defined by a center $C$, an axis $\vec{v}$, a diameter, and a height $h$.

We project the ray perpendicularly to the cylinder axis, which gives a quadratic equation ($a$, $b$, $c$) solved by `solve_quadratic`.

For each solution $t$, we check that the intersection point lies within the cylinder height by computing :

$$m = (\vec{d} \cdot \vec{v}) \cdot t + (\vec{oc} \cdot \vec{v})$$

The point is valid if $0 \leq m \leq h$. We return the smallest valid $t$.

</details>

## 💻 Instructions

### Compilation

To compile the project and generate the `miniRT` executable, run:

```bash
make
```

Then run the executable `miniRT` + `[test-address]`

You can find tests in the `./tests` folder and generate them with the .sh script located there.

Have fun :D
