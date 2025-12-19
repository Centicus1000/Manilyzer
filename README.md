# Manilyzer
### Manifold Analyzer, fast computation of sensorimotor manifolds.

Code is drafted and tested in python (ManiPy) as it is faster at writing time. Code modules that are mature enough and do not undergo frequent refactoring any more are translated into C++ (Manilyzer) as it is faster at run time. This project can then be used to accelerate computation.

Long-Term Goals:
- Terminal script to compute sensorimotor manifolds
- Python wrapper
- App with UI to view and animate robots and manifolds

### Repo Structure
The code (.cpp and .hpp files) are contained in the "code"-folder. The subfolders correspond to *modules* of the project. The order is based on dependency:
1. **test**: functions the run test data for each class to test if the implementations are correct
1. **utils**: miscellaneous mathematical definitions
2. **arc**: definition of the arc representation, an extension of polygon representation that can also handle circular arcs

### Scripts
On Mac, run `sh build_exe.sh` in the root folder. The script will compile the project using CMake into a new folder called "build_exe". Then it will run the executable.

## TODOs
- arc
  - ArcShape
  - ShapeConstructor
  - ShapeStyle
  - Cashew
  - Circle
- morphology
  - CenterOfMass
  - MorphNode
  - MorphEdge
  - Morphology
- physics
  - State3
  - Limb
  - Body
  - GroundContact
  - Posture
  - StabilizeAlgo
  - Torque
  - Equilibrium
  - SimulateAlgo
  - Physics
  - Anchor
  - Intersection
  - Collision
- manifold
  - ManiSpace
  - ManiNode
  - ManiGraph
  - ManiAlgo
  - Manifold
- robot
- generate manifold script