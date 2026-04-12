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

## 📐 Maths

<details>
<summary><strong>Rayon (dir)</strong></summary>

Pour chaque pixel de l'écran, on construit un vecteur directeur `dir` dans l'espace monde à partir de la base caméra (`camera_space`).

On calcule les coordonnées du pixel dans le viewport :

$$vpx = \left(\frac{2(x + 0.5)}{W} - 1\right) \cdot \frac{W}{H} \cdot \tan\!\left(\frac{fov}{2}\right)$$

$$vpy = \left(1 - \frac{2(y + 0.5)}{H}\right) \cdot \tan\!\left(\frac{fov}{2}\right)$$

Puis on combine avec les vecteurs de la base caméra (right = `camera_space.x`, up = `camera_space.y`, forward = `camera_space.z`) :

$$\vec{dir} = vpx \cdot \vec{right} + vpy \cdot \vec{up} + \vec{forward}$$

Le rayon est ensuite normalisé.

</details>

<details>
<summary><strong>Base caméra (camera_space / create_space)</strong></summary>

On construit un repère orthonormé à partir du vecteur directeur de la caméra (`camera->vector`) :

- `forward` (`camera_space.z`) = `camera->vector` (déjà normalisé depuis le parsing)
- `right` (`camera_space.y`) = `vectoriel_product(forward, up_world)` avec `up_world = (0, 1, 0)`
- `up` (`camera_space.x`) = `vectoriel_product(right, forward)`

Cas particulier : si la caméra regarde pile vers le haut ou le bas, on choisit un autre `up_world` pour éviter un produit vectoriel nul.

</details>

<details>
<summary><strong>Intersection sphère (distance_sphere)</strong></summary>

On substitue l'équation du rayon $P(t) = O + t\vec{d}$ dans l'équation cartésienne de la sphère :

$$(x - C_x)^2 + (y - C_y)^2 + (z - C_z)^2 = r^2$$

En posant $\vec{oc} = O_{cam} - C_{sphere}$, on obtient une équation du 2nd degré en $t$ :

$$t^2 (\vec{d} \cdot \vec{d}) + 2t (\vec{oc} \cdot \vec{d}) + (\vec{oc} \cdot \vec{oc} - r^2) = 0$$

Si le discriminant $\Delta \geq 0$, le rayon touche la sphère. On prend le plus petit $t > 0$.

</details>

<details>
<summary><strong>Intersection plan (distance_plane)</strong></summary>

Un plan est défini par un point $C$ et une normale $\vec{n}$. On cherche le $t$ tel que le rayon touche le plan :

$$t = \frac{\vec{n} \cdot (C - O)}{\vec{n} \cdot \vec{d}}$$

Si le dénominateur $\vec{n} \cdot \vec{d} \approx 0$, le rayon est parallèle au plan → pas d'intersection. On retourne $t$ seulement si $t > 0$.

</details>

<details>
<summary><strong>Intersection cylindre (distance_cylinder)</strong></summary>

Le cylindre est défini par un centre $C$, un axe $\vec{v}$, un diamètre et une hauteur $h$.

On projette le rayon perpendiculairement à l'axe du cylindre, ce qui donne une équation du 2nd degré ($a$, $b$, $c$) résolue par `solve_quadratic`.

Pour chaque solution $t$, on vérifie que le point d'intersection est dans la hauteur du cylindre en calculant :

$$m = (\vec{d} \cdot \vec{v}) \cdot t + (\vec{oc} \cdot \vec{v})$$

Le point est valide si $0 \leq m \leq h$. On retourne le plus petit $t$ valide.

</details>

## 💻 Instructions

### Compilation

To compile the project and generate the `miniRT` executable, run:

```bash
make
