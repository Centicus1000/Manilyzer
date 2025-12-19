#pragma once

#include "utils/Jsonable.hpp"
#include "utils/Vec2.hpp"

class Transform: public Jsonable<Transform>
{
public:
    double x, y, r;
    
    // Constructors
    Transform(double, double, double);
    static Transform Identity();

    // JSON serialization (requires JSON library)
    void WriteJson(json& jOut) const override;
    void ReadJson (json const& jIn ) override;

    /**
     * @brief Offset vector
     */
    Vec2 p() const;

    /**
     * @brief unit vector pointing in the direction given by r 
     */
    Vec2 v() const;

    /**
     * @brief Dot product
     * Similar to matrix multiplication of two affine transforms, this composes to Transforms into a single one, first the right hand (other) then this one.
     */
    Transform Dot(Transform const& other) const;

    /**
     * @brief Scales the transform by a scalar
     */
    Transform Scaled(double scale) const;

    // Arithmetic operators
    Transform operator+(Transform const& other) const;
    Transform operator-(Transform const& other) const;
    Transform operator-() const;
};