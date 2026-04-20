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
    * **Shadows:** Objects accurately block light sources.
* **Camera:** Fully adjustable view point, direction, and Field of View (FOV).
* **Scene Parsing:** Reads `.rt` files to define objects, lights, and camera settings.

## 🛠 Technical Choices

The engine follows a **ray-casting** approach: one ray is fired from the camera for each pixel. We implemented a small linear-algebra toolkit to handle vector operations (addition, normalization, cross product, dot product, and vector angles). The core rendering logic solves geometric equations to find the closest intersection point $t$ for spheres, planes, and cylinders. A simple lighting model is then applied to produce light intensity variations and shadows.

## 📐 Maths

<details>
<summary><strong>Rayon (dir)</strong></summary>

For each pixel `(x, y)`, the code builds one camera ray in world space.

Viewport coordinates are:

$$vpx = \left(2\frac{x + 0.5}{W} - 1\right) \cdot \frac{W}{H} \cdot \tan\left(\frac{fov}{2}\right)$$

$$vpy = \left(1 - 2\frac{y + 0.5}{H}\right) \cdot \tan\left(\frac{fov}{2}\right)$$

Then:

$$\vec d = vpx\,\vec x_{cam} + vpy\,\vec y_{cam} + \vec z_{cam}$$

and `dir = normalize(d)`.

</details>

<details>
<summary><strong>Camera basis (camera_space / create_space)</strong></summary>

The basis is built from camera forward and a world-up helper:

* $\vec z_{cam} = normalize(camera\_vector)$
* choose $\vec u = (0,1,0)$, but if $|\vec z_{cam}\cdot\vec u| > 0.999$, use $\vec u=(0,0,1)$
* $\vec x_{cam} = normalize(\vec z_{cam} \times \vec u)$
* $\vec y_{cam} = normalize(\vec x_{cam} \times \vec z_{cam})$

This avoids degenerate cross products when looking almost straight up/down.

</details>

<details>
<summary><strong>Sphere intersection (distance_sphere)</strong></summary>

Ray equation:

$$P(t)=O+t\vec d$$

With $\vec{oc}=O-C$ and radius $r$, the code evaluates:

$$\Delta=(\vec d\cdot\vec{oc})^2-(\vec d\cdot\vec d)\left((\vec{oc}\cdot\vec{oc})-r^2\right)$$

If $\Delta > 0$:

$$t_{\pm}=\frac{-\vec d\cdot\vec{oc}\pm\sqrt\Delta}{\vec d\cdot\vec d}$$

The chosen hit is the smallest positive $t$.

</details>

<details>
<summary><strong>Plane intersection (distance_plane)</strong></summary>

Plane is point $C$ + normal $\vec n$.

$$t=\frac{\vec n\cdot(C-O)}{\vec n\cdot\vec d}$$

If denominator is near zero (`-1e-6 < denom < 1e-6`), ray is parallel, no hit.

</details>

<details>
<summary><strong>Cylinder intersection (distance_cylinder)</strong></summary>

Let $\vec v$ be cylinder axis (normalized), $\vec{oc}=O-C$, radius $r$.
The implemented quadratic coefficients are:

$$a = \vec d\cdot\vec d - (\vec d\cdot\vec v)^2$$

$$b = 2\left[(\vec d\cdot\vec{oc})-(\vec d\cdot\vec v)(\vec{oc}\cdot\vec v)\right]$$

$$c = \vec{oc}\cdot\vec{oc}-(\vec{oc}\cdot\vec v)^2-r^2$$

For each root $t$, height clipping uses:

$$m=(\vec d\cdot\vec v)t+(\vec{oc}\cdot\vec v)$$

Valid if $0\le m\le h$. Keep smallest valid positive $t$.

</details>

<details>
<summary><strong>Normals used for lighting</strong></summary>

At hit point $P$:

* Sphere: $\vec n = P-C$
* Plane: $\vec n = \vec v_{plane}$
* Cylinder side:

$$m=(\vec d\cdot\vec v)t + ((O-C)\cdot\vec v)$$

$$\vec n = (P-C)-m\vec v$$

Normals are then used with angle-based lighting.

</details>

<details>
<summary><strong>Luminosity (ambient + diffuse)</strong></summary>

For each visible object point:

1. Build light ray: $\vec l = L-P$
2. Compute angle $\theta=\angle(\vec n,\vec l)$
3. If $\theta>\pi/2$, use shadow/ambient-only color
4. Else diffuse factor is:

$$deg = \cos(|\theta|)$$

This is exactly Lambert's cosine law: received diffuse light is proportional to
the cosine of the incidence angle between the surface normal and the light
direction.

With normalized vectors, this is equivalent to a dot product:

$$deg = \max(0, \hat n \cdot \hat l)$$

where

$$\hat n = \frac{\vec n}{||\vec n||}, \qquad \hat l = \frac{\vec l}{||\vec l||}$$

Interpretation:

* if light is perpendicular to the surface ($\theta=0$), $\cos\theta=1$ => max diffuse
* if light is grazing ($\theta\approx 90^\circ$), $\cos\theta\approx 0$ => weak diffuse
* if light comes from behind ($\theta>90^\circ$), diffuse is clamped to 0

In this project, the code computes `theta` with `angle_vect(normal, ray)` and
then uses `cos(fabs(theta))`, with the front/back test done before applying
diffuse (`if angle > PI/2 => shadow/ambient only`).

Channel-wise in code:

$$R = R_{obj}\left(A_r\cdot A_{ratio}/255 + deg\right)$$
$$G = G_{obj}\left(A_g\cdot A_{ratio}/255 + deg\right)$$
$$B = B_{obj}\left(A_b\cdot A_{ratio}/255 + deg\right)$$

Then clamp each channel to `[0, 255]`.

Note: in this mandatory version, diffuse does not use light RGB/brightness as a separate multiplier; it is driven by `deg` plus ambient term.

</details>

<details>
<summary><strong>Shadows (check_coalition)</strong></summary>

From hit point $P$, cast a shadow ray toward light:

$$\vec d_s = normalize(L-P)$$

An object blocks light if it intersects this ray with distance `t` such that:

$$t > 0.001 \quad \text{and} \quad t < ||L-P||$$

This is checked against spheres, planes, and cylinders. If any blocks, color falls back to ambient-only (`color_to_shadow`).

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
