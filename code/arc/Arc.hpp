#pragma once

#include "utils/Vec2.hpp"
#include "utils/Transform.hpp"

class Arc
{
public:

    double x, y;  // starting point coordinates arc
    double a;  // starting angle of arc
    double k;  // curvature of arc, positive bends clockwise
    double l;  // arc length


    Arc(double, double, double, double, double);

    /**
     * @brief Checks if the arc is actually a straight line (curvature = 0)
     */
    bool IsStraight() const;

    // ----------------------------------------------
    
    /**
     * @brief Postion where arc begins (Vec2)
     */
    Vec2 bgn() const;
    Vec2 Begin() const;

    /**
     * @brief Radius of the corresponding Arc (only valid if arc is not straight)
     */
    double r() const;
    double Radius() const;

    /**
     * @brief Central Angle
     */
    double ca() const;
    double CentralAngle() const;

    /**
     * @brief Center of corresponding Circle (Vec2)
     */
    Vec2 cp() const;
    Vec2 CenterPoint() const;

    // ----------------------------------------------
    // Sampling

    /**
     * @brief Sampling along the starting tangent
     */
    Vec2 AtTangent(double length) const;

    /**
     * @brief Sampling along the arc at a given length (not necessarily the length of the arc)
     */
    Vec2 AtLength(double length) const;

    /**
     * @brief Samples the arc in relative units, 0: begin, 1: end
     */
    Vec2 AtPercent(double percent) const;

    /**
     * @brief Returns the point on the corresponding circle at a given absolute angle
     */
    Vec2 AtAngle(double angle) const;

    /// @TODO: SampleLine(self, nSamples)

    // ----------------------------------------------

    /**
     * @brief End point of the arc
     */
    Vec2 end() const;
    Vec2 EndPoint() const;
    double ex() const;
    double ey() const;

    // ----------------------------------------------

    /**
     * @brief True, if the arc reaches the given absolute angle
     */
    bool Reaches(double angle) const;

    /**
     * @brief Transforms (translates and rotates) the Arc (mutates data)
     */
    void ApplyT(Transform T);
};

/**
    def SectorContains(self, p: Vec2) -> bool:
        """ True, if the point lies within the arcs sector (continues infinitely) """
        if self.IsStraight(): return False  # straight line hav no sector
        return self.Reaches((p - self.c()).Argument())

    def NextArc(self):
        return Arc(self.ex(), self.ey(), self.a + self.ca(), -self.k, self.l)

    @staticmethod
    def Random():
        return Arc(
            np.random.normal(0, 1),
            np.random.normal(0, 1),
            np.random.uniform(0, 2 * np.pi),
            np.random.uniform(-2, 2),
            np.random.uniform(1, 5)
        )
*/