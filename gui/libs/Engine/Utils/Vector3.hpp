/*
** EPITECH PROJECT, 2021
** IndieStudio
** File description:
** Vector3
*/

#pragma once

#include <ostream>
#include <cmath>

namespace utils
{
    template<typename U>
    struct Vector2;

    template<typename T>
    struct Vector3
    {
        T x = 0;
        T y = 0;
        T z = 0;

        Vector3() noexcept = default;
        Vector3(T xyz) noexcept : x{xyz}, y{xyz}, z{xyz} {};
        Vector3(T x, T y, T z) noexcept : x{x}, y{y}, z{z} {};
        template<typename U, typename V, typename W>
        explicit Vector3(U x, V y, W z) noexcept :
                                    x{static_cast<T>(x)},
                                    y{static_cast<T>(y)},
                                    z{static_cast<T>(z)}
                                    {};
        template<typename U>
        Vector3(const Vector3<U> &other) noexcept :
                                    x{static_cast<T>(other.x)},
                                    y{static_cast<T>(other.y)},
                                    z{static_cast<T>(other.z)}
                                    {};
        template<typename U>
        Vector3(const Vector2<U> &v2) noexcept : x{v2.x}, y{v2.y} {};

        /**
         * @brief Shorthand for writing Vector3(1, 0, 0).
         */
        static Vector3 right() noexcept { return Vector3{1, 0, 0}; };

        /**
         * @brief Shorthand for writing Vector3(-1, 0, 0).
         */
        static Vector3 left() noexcept  { return Vector3{-1, 0, 0}; };

        /**
         * @brief Shorthand for writing Vector3(0, -1, 0).
         */
        static Vector3 down() noexcept  { return Vector3{0, -1, 0}; };

        /**
         * @brief Shorthand for writing Vector3(0, 1, 0).
         */
        static Vector3 up() noexcept    { return Vector3{0, 1, 0}; };

        /**
         * @brief Shorthand for writing Vector3(0, 0, -1).
         */
        static Vector3 back() noexcept  { return Vector3{0, 0, -1}; };

        /**
         * @brief Shorthand for writing Vector3(0, 0, 1).
         */
        static Vector3 forward() noexcept   { return Vector3{0, 0, 1}; };

        /**
         * @brief Shorthand for writing Vector3(0, 0, 0).
         */
        static Vector3 zero() noexcept  { return Vector3{0, 0, 0}; };

        /**
         * @brief Shorthand for writing Vector3(1, 1, 1).
         */
        static Vector3 one() noexcept   { return Vector3{1, 1, 1}; };

        /**
         * @brief Return the Vector3's norm.
         */
        float norm() const noexcept { 
            return std::sqrt((x * x) + (y * y) + (z * z));
        };

        /**
         * @brief Normalize the Vector3 itself.
         */
        void normalize() noexcept {
            float n = norm();
            x /= std::abs(n);
            y /= std::abs(n);
            z /= std::abs(n);
        };

        /**
         * @brief Normalized version of the Vector3.
         */
        Vector3 normalized() const noexcept {
            float n = norm();
            return Vector3{(x / n), (y / n), (z / n)};
        };

        /**
         * @brief Distance between two points
         */
        static float distance(const Vector3 &a, const Vector3 &b) {
            return std::sqrt( ((b.x - a.x) * (b.x - a.x))
                            + ((b.y - a.y) * (b.y - a.y))
                            + ((b.z - a.z) * (b.z - a.z)));
        };
        float distance(const Vector3 &b) {
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
         * @return Vector3 Interpolated value, equals to a + (b - a) * t.
         */
        static Vector3 lerp(const Vector3 &a, const Vector3 &b, float t) {
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
         * @return Vector3 The new position. 
         */
        static Vector3 moveTowards(const Vector3 &curr, const Vector3 target, float maxDistanceDelta) {
            Vector3 res = curr;
            float direction;

            direction = curr.x <= target.x ? 1 : -1;
            res.x += std::abs(target.x - res.x) > maxDistanceDelta ? maxDistanceDelta * direction : target.x - res.x;
            direction = curr.y <= target.y ? 1 : -1;
            res.y += std::abs(target.y - res.y) > maxDistanceDelta ? maxDistanceDelta * direction : target.y - res.y;
            direction = curr.z <= target.z ? 1 : -1;
            res.z += std::abs(target.z - res.z) > maxDistanceDelta ? maxDistanceDelta * direction : target.z - res.z;
            return res;
        };
        Vector3 &moveTowards(const Vector3 &target, float maxDistanceDelta) {
            *this = moveTowards(*this, target, maxDistanceDelta);
            return *this;
        };

        template<typename U>
        Vector3 &operator=(const Vector3<U> &other) noexcept {
            x = static_cast<T>(other.x);
            y = static_cast<T>(other.y);
            z = static_cast<T>(other.z);
            return *this;
        };
        template<typename U>
        Vector3 &operator=(const Vector2<U> &other) noexcept {
            x = static_cast<T>(other.x);
            y = static_cast<T>(other.y);
            z = 0;
            return *this;
        };

        template<typename U>
        Vector3 &operator+=(const Vector3<U> &other) noexcept {
            x += static_cast<T>(other.x);
            y += static_cast<T>(other.y);
            z += static_cast<T>(other.z);
            return *this;
        };
        template<typename U>
        Vector3 &operator+=(const Vector2<U> &other) noexcept {
            x += static_cast<T>(other.x);
            y += static_cast<T>(other.y);
            return *this;
        };
        template<typename U>
        Vector3 &operator+=(U value) noexcept {
            x += static_cast<T>(value);
            y += static_cast<T>(value);
            z += static_cast<T>(value);
            return *this;
        };

        template<typename U>
        Vector3 &operator-=(const Vector3<U> &other) noexcept {
            x -= static_cast<T>(other.x);
            y -= static_cast<T>(other.y);
            z -= static_cast<T>(other.z);
            return *this;
        };
        template<typename U>
        Vector3 &operator-=(const Vector2<U> &other) noexcept {
            x -= static_cast<T>(other.x);
            y -= static_cast<T>(other.y);
            return *this;
        };
        template<typename U>
        Vector3 &operator-=(U value) noexcept {
            x -= static_cast<T>(value);
            y -= static_cast<T>(value);
            z -= static_cast<T>(value);
            return *this;
        };

        template<typename U>
        Vector3 &operator*=(const Vector3<U> &other) noexcept {
            x *= static_cast<T>(other.x);
            y *= static_cast<T>(other.y);
            z *= static_cast<T>(other.z);
            return *this;
        };
        template<typename U>
        Vector3 &operator*=(U value) noexcept {
            x *= static_cast<T>(value);
            y *= static_cast<T>(value);
            z *= static_cast<T>(value);
            return *this;
        };

        template<typename U>
        Vector3 &operator/=(const Vector3<U> &other) noexcept {
            x /= static_cast<T>(other.x);
            y /= static_cast<T>(other.y);
            z /= static_cast<T>(other.z);
            return *this;
        };
        template<typename U>
        Vector3 &operator/=(U value) noexcept {
            x /= static_cast<T>(value);
            y /= static_cast<T>(value);
            z /= static_cast<T>(value);
            return *this;
        };

        operator bool() const noexcept {
            return x && y && z;
        }
    };

    template<typename T, typename U>
    inline Vector3<T> operator+(const Vector3<T> &left, const Vector3<U> &right) {
        return Vector3<T>{left.x + static_cast<T>(right.x)
                        , left.y + static_cast<T>(right.y)
                        , left.z + static_cast<T>(right.z)};
    };
    template<typename T, typename U>
    inline Vector3<T> operator+(const Vector3<T> &left, const Vector2<U> &right) {
        return Vector3<T>{left.x + static_cast<T>(right.x)
                        , left.y + static_cast<T>(right.y)
                        , left.z};
    };
    template<typename T, typename U>
    inline Vector3<T> operator-(const Vector3<T> &left, const Vector3<U> &right) {
        return Vector3<T>{left.x - static_cast<T>(right.x)
                        , left.y - static_cast<T>(right.y)
                        , left.z - static_cast<T>(right.z)};
    };
    template<typename T, typename U>
    inline Vector3<T> operator-(const Vector3<T> &left, const Vector2<U> &right) {
        return Vector3<T>{left.x - static_cast<T>(right.x)
                        , left.y - static_cast<T>(right.y)
                        , left.z};
    };
    template<typename T, typename U>
    inline Vector3<T> operator*(const Vector3<T> &left, const Vector3<U> &right) {
        return Vector3<T>{left.x * static_cast<T>(right.x)
                        , left.y * static_cast<T>(right.y)
                        , left.z * static_cast<T>(right.z)};
    };
    template<typename T, typename U>
    inline Vector3<T> operator*(const Vector3<T> &left, U value) {
        return Vector3<T>{left.x * value
                        , left.y * value
                        , left.z * value};
    };
    template<typename T, typename U>
    inline Vector3<T> operator/(const Vector3<T> &left, const Vector3<U> &right) {
        return Vector3<T>{left.x / static_cast<T>(right.x)
                        , left.y / static_cast<T>(right.y)
                        , left.z / static_cast<T>(right.z)};
    };
    template<typename T, typename U>
    inline Vector3<T> operator/(const Vector3<T> &left, U value) {
        return Vector3<T>{left.x / value
                        , left.y / value
                        , left.z / value};
    };
    template<typename T, typename U>
    inline bool operator==(const Vector3<T> &left, const Vector3<U> &right) {
        return left.x == static_cast<T>(right.x)
            && left.y == static_cast<T>(right.y)
            && left.z == static_cast<T>(right.z);
    };

    typedef Vector3<float>          Vector3f;
    typedef Vector3<int>            Vector3i;
    typedef Vector3<unsigned int>   Vector3u;

    template<typename T>
    inline std::ostream& operator<<(std::ostream& stream, const Vector3<T> &vector) {
        stream << '(' << vector.x << ", " << vector.y << ", " << vector.z << ')';
        return stream;
    };
};
