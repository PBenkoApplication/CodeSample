#ifndef MATH_H
#define MATH_H
#include "../Geometry/Vertex.h"

namespace BAME
{
#define SANEFLOATEQUALRANGE 0.0000001

	namespace Math
	{
		static const float M_PI = 3.14159265358979323846f;
		static const float M_2PI = 6.283185307f;
		static const float M_1DIVPI = 0.318309886f;
		static const float M_1DIV2PI = 0.159154943f;
		static const float M_HALFPI = 1.570796327f;
		static const float M_QUADPI = 0.785398163f;


		static float SinScalar(const float Value)
		{
			// Map Value to y in [-pi,pi], x = 2*pi*quotient + remainder.
			float quotient = M_1DIV2PI * Value;
			if (Value >= 0.0f)
			{
				quotient = float(int(quotient + 0.5f));
			}
			else
			{
				quotient = float(int(quotient - 0.5f));
			}
			float y = Value - M_2PI * quotient;

			// Map y to [-pi/2,pi/2] with sin(y) = sin(Value).
			float sign;
			if (y > M_HALFPI)
			{
				y = M_PI - y;
				sign = -1.0f;
			}
			else if (y < -M_HALFPI)
			{
				y = -M_PI - y;
				sign = -1.0f;
			}
			else
			{
				sign = +1.0f;
			}

			float y2 = y * y;

			// 11-degree minimax approximation
			return (((((-2.3889859e-08f * y2 + 2.7525562e-06f) * y2 - 0.00019840874f) * y2 + 0.0083333310f) * y2 - 0.16666667f) * y2 + 1.0f) * y;
		}

		static float CosScalar(const float Value)
		{
			// Map Value to y in [-pi,pi], x = 2*pi*quotient + remainder.
			float quotient = Math::M_1DIV2PI * Value;
			if (Value >= 0.0f)
			{
				quotient = float(int(quotient + 0.5f));
			}
			else
			{
				quotient = float(int(quotient - 0.5f));
			}
			float y = Value - Math::M_2PI * quotient;

			// Map y to [-pi/2,pi/2] with sin(y) = sin(Value).
			float sign;
			if (y > Math::M_HALFPI)
			{
				y = M_PI - y;
				sign = -1.0f;
			}
			else if (y < -M_HALFPI)
			{
				y = -M_PI - y;
				sign = -1.0f;
			}
			else
			{
				sign = +1.0f;
			}

			float y2 = y * y;

			float p = ((((-2.6051615e-07f * y2 + 2.4760495e-05f) * y2 - 0.0013888378f) * y2 + 0.041666638f) * y2 - 0.5f) * y2 + 1.0f;
			return sign * p;
		}


		inline static float ToRadians(const float degree)
		{
			return float(degree * M_PI / 180.0f);
		}

		inline static float ToDegree(const float radian)
		{
			return float(radian * 180.0f / M_PI);
		}

		inline static bool IsEqual(const float f1, const float f2)
		{
			if (f1 <= f2 + SANEFLOATEQUALRANGE && f1 >= f2 - SANEFLOATEQUALRANGE)
			{
				return true;
			}
			return false;
		}

		static int getRandNumber(int min, int max)
		{
			//srand(static_cast<unsigned>(time(nullptr)));

			int range = static_cast<int>((max - min) + 1.0);
			int random_integer = min + int(range * rand() / (RAND_MAX + 1.0));
			return random_integer;
		};

		inline static float getRandNumberF(float min, float max)
		{
			/*srand(static_cast<unsigned>(time(nullptr)));*/
			float range = static_cast<float>((max - min) + 1.0);

			return static_cast<float>(min + (range * rand() / (RAND_MAX + 1.0)));
		};

		static Vector3f getRandomInsideUnitSphere()
		{
			float randomAnglePhi = ToRadians(getRandNumberF(0, 360));
			float randomAngleSigma = ToRadians(getRandNumberF(0, 360));

			return Vector3f(sin(randomAnglePhi) * cos(randomAngleSigma), sin(randomAnglePhi) * sin(randomAngleSigma), cos(randomAnglePhi));
		}


		static Vector4f Vec3ToVec4(Vector3f const& vec)
		{
			return Vector4f(vec.GetX(), vec.GetY(), vec.GetZ(),1);
		}

		static Vector3f Vec4ToVec3(Vector4f const& vec)
		{
			return Vector3f(vec.GetX(), vec.GetY(), vec.GetZ());
		}

		static Vector3f Vec4ToVec3Normalized(Vector4f const& vec)
		{
			return Vector3f(vec.GetX(), vec.GetY(), vec.GetZ())/vec.GetW();
		}
		
		static float DistancePointToPointDirected(Vector3f const& startPoint, Vector3f const& endPoint, Vector3f const& posDirection)
		{
			Vector3f vectorStartToEnd = endPoint - startPoint;
			float distance = vectorStartToEnd.Length();

			float direction = posDirection.Normalized().Dot(vectorStartToEnd.Normalized());

			if (direction < 0)
				distance = -distance;

			return distance;
		}
	};
}

#endif
