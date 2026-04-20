# miniRT eval scenes

Ces fichiers couvrent les questions de la grille d'evaluation miniRT.

## Configuration file
- `00_config/valid_minimal.rt`
- `00_config/invalid_missing_acl.rt` (doit echouer)
- `00_config/invalid_bad_identifier.rt` (doit echouer)
- `00_config/invalid_bad_rgb.rt` (doit echouer)

## Technical elements of the display
- `01_display/window_stability.rt`

## Basic shapes
- `02_basic_shapes/sphere_origin.rt`
- `02_basic_shapes/plane_z0.rt`
- `02_basic_shapes/cylinder_y_axis.rt`

## Translations and rotations
- `03_transforms/two_spheres_translated.rt`
- `03_transforms/cylinder_rotated_z_90.rt`

## Multi-objects
- `04_multi_objects/intersection_sphere_cylinder.rt`
- `04_multi_objects/many_duplicates.rt`

## Camera position and direction
- `05_camera_axes/camera_on_x_axis.rt`
- `05_camera_axes/camera_on_y_axis.rt`
- `05_camera_axes/camera_on_z_axis.rt`
- `05_camera_axes/camera_random_axis.rt`

## Brightness 1/2
- `06_brightness/side_light_sphere_origin.rt`
- `06_brightness/side_light_translated_sphere.rt`

## Brightness 2/2 (shadows)
- `07_shadows/sphere_shadow_on_plane.rt`
- `07_shadows/complex_shadows_scene.rt`

## Usage
Depuis la racine du projet:

```bash
./miniRT tests/eval/02_basic_shapes/sphere_origin.rt
```

Pour le test extension `.rt`, lance aussi un fichier avec une autre extension (par exemple copier un fichier vers `.txt`).
