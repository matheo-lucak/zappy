/*
** EPITECH PROJECT, 2021
** IndieStudio
** File description:
** Vector2
*/

#pragma once

#include <ostream>
#include <cmath>

namespace utils
{
    template<typename U>
    struct Vector3;

    template<typename T>
    struct Vector2
    {
        T x = 0;
        T y = 0;

        Vector2() noexcept = default;
        Vector2(T xy) noexcept : x{xy}, y{xy} {};
        Vector2(T x, T y) noexcept : x{x}, y{y} {};
        template<typename U, typename V>
        explicit Vector2(U x, V y) noexcept :
                                    x{static_cast<T>(x)},
                                    y{static_cast<T>(y)}
                                    {};
        template<typename U>
        Vector2(const Vector2<U> &other) noexcept :
                                    x{static_cast<T>(other.x)},
                                    y{static_cast<T>(other.y)}
                                    {};
        template<typename U>
        Vector2(const Vector3<U> &v3) noexcept : x{v3.x}, y{v3.y} {};

        /**
         * @brief Shorthand for writing Vector2(1, 0).
         */
        static Vector2 right() noexcept { return Vector2{1, 0}; };

        /**
         * @brief Shorthand for writing Vector2(-1, 0).
         */
        static Vector2 left() noexcept  { return Vector2{-1, 0}; };

        /**
         * @brief Shorthand for writing Vector2(0, -1).
         */
        static Vector2 down() noexcept  { return Vector2{0, -1}; };

        /**
         * @brief Shorthand for writing Vector2(0, 1).
         */
        static Vector2 up() noexcept    { return Vector2{0, 1}; };

        /**
         * @brief Shorthand for writing Vector2(0, 0).
         */
        static Vector2 zero() noexcept  { return Vector2{0, 0}; };

        /**
         * @brief Shorthand for writing Vector2(1, 1).
         */
        static Vector2 one() noexcept   { return Vector2{1, 1}; };

        /**
         * @brief Return the Vector2's norm.
         */
        float norm() const noexcept { 
            return std::sqrt((x * x) + (y * y));
        };

        /**
         * @brief Normalize the Vector2 itself.
         */
        void normalize() noexcept {
            float n = norm();
            x /= std::abs(n);
            y /= std::abs(n);
        };

        /**
         * @brief Normalized version of the Vector2.
         */
        Vector2 normalized() const noexcept {
            float n = norm();
            return Vector2{(x / n), (y / n)};
        };

        /**
         * @brief Distance between two points
         */
        static float distance(const Vector2 &a, const Vector2 &b) {
            return std::sqrt( ((b.x - a.x) * (b.x - a.x))
                            + ((b.y - a.y) * (b.y - a.y)));
        };
        float distance(const Vector2 &b) {
            return distance(*this, b);
        };

        /**
         * @brief   Linearly interpolates between two points. 
         *          Interpolates between the points a and b by the interpolant t.
         *          The parameter t is clamped to the range [0, 1].
         * 
         * @param a Start value, returned when t = 0.
         * @param b End value, returned when t = 1.
         * @param t Value used to interpolate between a and b.
         * @return Vector2 Interpolated value, equals to a + (b - a) * t.
         */
        static Vector2 lerp(const Vector2 &a, const Vector2 &b, float t) {
            t = t < 0 ? 0 : t > 1 ? 1 : t;
            return a + (b - a) * t;
        };

        /**
         * @brief   Calculate a position between the points specified by current and target,
         *          moving no farther than the distance specified by maxDistanceDelta.
         * 
         * @param curr The position to move from.
         * @param target The position to move towards.
         * @param maxDistanceDelta Distance to move current per call.
         * @return Vector2 The new position. 
         */
        static Vector2 moveTowards(const Vector2 &curr, const Vector2 target, float maxDistanceDelta) {
            Vector2 res = curr;
            float direction;

            direction = curr.x <= target.x ? 1 : -1;
            res.x += std::abs(target.x - res.x) > maxDistanceDelta ? maxDistanceDelta * direction : target.x - res.x;
            direction = curr.y <= target.y ? 1 : -1;
            res.y += std::abs(target.y - res.y) > maxDistanceDelta ? maxDistanceDelta * direction : target.y - res.y;
            return res;
        };
        Vector2 &moveTowards(const Vector2 &target, float maxDistanceDelta) {
            *this = moveTowards(*this, target, maxDistanceDelta);
            return *this;
        };

        template<typename U>
        Vector2 &operator=(const Vector2<U> &other) noexcept {
            x = static_cast<T>(other.x);
            y = static_cast<T>(other.y);
            return *this;
        };
        template<typename U>
        Vector2 &operator=(const Vector3<U> &other) noexcept {
            x = static_cast<T>(other.x);
            y = static_cast<T>(other.y);
            return *this;
        };

        template<typename U>
        Vector2 &operator+=(const Vector2<U> &other) noexcept {
            x += static_cast<T>(other.x);
            y += static_cast<T>(other.y);
            return *this;
        };
        template<typename U>
        Vector2 &operator+=(const Vector3<U> &other) noexcept {
            x += static_cast<T>(other.x);
            y += static_cast<T>(other.y);
            return *this;
        };

        template<typename U>
        Vector2 &operator-=(const Vector2<U> &other) noexcept {
            x -= static_cast<T>(other.x);
            y -= static_cast<T>(other.y);
            return *this;
        };
        template<typename U>
        Vector2 &operator-=(const Vector3<U> &other) noexcept {
            x -= static_cast<T>(other.x);
            y -= static_cast<T>(other.y);
            return *this;
        };

        template<typename U>
        Vector2 &operator*=(const Vector2<U> &other) noexcept {
            x *= static_cast<T>(other.x);
            y *= static_cast<T>(other.y);
            return *this;
        };
        template<typename U>
        Vector2 &operator*=(U value) noexcept {
            x *= static_cast<T>(value);
            y *= static_cast<T>(value);
            return *this;
        };

        template<typename U>
        Vector2 &operator/=(const Vector2<U> &other) noexcept {
            x /= static_cast<T>(other.x);
            y /= static_cast<T>(other.y);
            return *this;
        };
        template<typename U>
        Vector2 &operator/=(U value) noexcept {
            x /= static_cast<T>(value);
            y /= static_cast<T>(value);
            return *this;
        };

        operator bool() const noexcept {
            return x && y;
        }
    };

    template<typename T, typename U>
    inline Vector2<T> operator+(const Vector2<T> &left, const Vector2<U> &right) {
        return Vector2<T>{left.x + static_cast<T>(right.x)
                        , left.y + static_cast<T>(right.y)};
    };
    template<typename T, typename U>
    inline Vector2<T> operator+(const Vector2<T> &left, const Vector3<U> &right) {
        return Vector2<T>{left.x + static_cast<T>(right.x)
                        , left.y + static_cast<T>(right.y)};
    };
    template<typename T, typename U>
    inline Vector2<T> operator-(const Vector2<T> &left, const Vector2<U> &right) {
        return Vector2<T>{left.x - static_cast<T>(right.x)
                        , left.y - static_cast<T>(right.y)};
    };
    template<typename T, typename U>
    inline Vector2<T> operator-(const Vector2<T> &left, const Vector3<U> &right) {
        return Vector2<T>{left.x - static_cast<T>(right.x)
                        , left.y - static_cast<T>(right.y)};
    };
    template<typename T, typename U>
    inline Vector2<T> operator*(const Vector2<T> &left, const Vector2<U> &right) {
        return Vector2<T>{left.x * static_cast<T>(right.x)
                        , left.y * static_cast<T>(right.y)};
    };
    template<typename T, typename U>
    inline Vector2<T> operator*(const Vector2<T> &left, const Vector3<U> &right) {
        return Vector2<T>{left.x * static_cast<T>(right.x)
                        , left.y * static_cast<T>(right.y)};
    };
    template<typename T, typename U>
    inline Vector2<T> operator*(const Vector2<T> &left, U value) {
        return Vector2<T>{left.x * value
                        , left.y * value};
    };
    template<typename T, typename U>
    inline Vector2<T> operator/(const Vector2<T> &left, const Vector2<U> &right) {
        return Vector2<T>{left.x / static_cast<T>(right.x)
                        , left.y / static_cast<T>(right.y)};
    };
    template<typename T, typename U>
    inline Vector2<T> operator/(const Vector2<T> &left, const Vector3<U> &right) {
        return Vector2<T>{left.x / static_cast<T>(right.x)
                        , left.y / static_cast<T>(right.y)};
    };
    template<typename T, typename U>
    inline Vector2<T> operator/(const Vector2<T> &left, U value) {
        return Vector2<T>{left.x / value
                        , left.y / value};
    };
    template<typename T, typename U>
    inline Vector2<T> operator==(const Vector2<T> &left, const Vector2<U> &right) {
        return left.x == static_cast<T>(right.x)
            && left.y == static_cast<T>(right.y);
    };
    template<typename T, typename U>
    inline Vector2<T> operator==(const Vector2<T> &left, const Vector3<U> &right) {
        return left.x == static_cast<T>(right.x)
            && left.y == static_cast<T>(right.y)
            && static_cast<T>(right.z) == 0;
    };

    typedef Vector2<float>          Vector2f;
    typedef Vector2<int>            Vector2i;
    typedef Vector2<unsigned int>   Vector2u;

    template<typename T>
    inline std::ostream& operator<<(std::ostream& stream, const Vector2<T> &vector) {
        stream << '(' << vector.x << ", " << vector.y << ')';
        return stream;
    };
};
