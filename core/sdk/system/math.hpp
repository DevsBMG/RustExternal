#pragma once
#include <math.h>
#include <algorithm>
#define M_PI 3.141592653589793238462643383279502884197169399375105820974944f
#define M_PI_2 1.57079632679489661923f
#define M_PI_F ((float)(M_PI))
#define RAD2DEG(x) ((float)(x) * (float)(180.f / M_PI_F))
#define max(a,b)			   (((a) > (b)) ? (a) : (b))
#define power_max(n) (n)*(n)
#define min(x,y) ((x)<(y) ? x:y)
#define wh(a) ImColor(1.f,1.f,1.f,a)

static inline float max3(float f1, float f2, float f3)
{
	return max(max(f1, f2), f3);
}

namespace geo
{
	class vec2_t
	{
	public:
		float x, y;

		vec2_t() { x = y = 0.00f; }

		vec2_t(float x, float y) { this->x = x; this->y = y; }

		auto operator+(const geo::vec2_t& input) -> geo::vec2_t { return geo::vec2_t{ x + input.x, y + input.y }; }

		auto operator-(const geo::vec2_t& input) -> geo::vec2_t { return geo::vec2_t{ x - input.x, y - input.y }; }

		auto operator==(const geo::vec2_t& input) -> bool { return x == input.x && y == input.y; }

		auto operator>(const geo::vec2_t& input) -> bool { return x > input.x && y > input.y; }

		auto operator<(const geo::vec2_t& input) -> bool { return x < input.x && y < input.y; }

		auto operator-=(const geo::vec2_t& v) -> geo::vec2_t { x -= v.x; y -= v.y; return *this; }

		auto operator/(const geo::vec2_t& input) -> geo::vec2_t { return geo::vec2_t{ x / input.x, y / input.y }; }

		auto operator*(const geo::vec2_t& input) -> geo::vec2_t { return geo::vec2_t{ x * input.x, y * input.y }; }

		auto operator+=(const geo::vec2_t& v) -> geo::vec2_t { x += v.x; y += v.y; return *this; }

		auto operator+(float input) -> geo::vec2_t { return geo::vec2_t{ x + input, y + input }; }

		auto operator-(float input) -> geo::vec2_t { return geo::vec2_t{ x - input, y - input }; }

		auto operator/(float input) -> geo::vec2_t { return geo::vec2_t{ x / input, y / input }; }

		auto operator/=(float input) -> geo::vec2_t { x /= input; y /= input; return *this; }

		auto operator*=(float input) -> geo::vec2_t { x *= input; y *= input; return *this; }

		auto operator*(float input) -> geo::vec2_t { return geo::vec2_t{ x * input, y * input }; }

		auto is_empty() -> bool
		{
			return this->x == 0.00f && this->y == 0.00f;
		}

		auto dot(geo::vec2_t input) -> float
		{
			return (x * input.x) + (y * input.y);
		}

		auto length_sqr() -> float
		{
			return (x * x) + (y * y);
		}

		auto length() -> float
		{
			return (float)sqrt(length_sqr());
		}

		auto distance(geo::vec2_t input) -> float
		{
			return (*this - input).length();
		}

		auto normalized() -> geo::vec2_t
		{
			auto length = this->length();
			return { this->x / length , this->y / length };
		}

		auto normalize() -> geo::vec2_t
		{
			float mag = this->length();
			if (mag > 0.00001f)
			{
				this->x = this->x / mag;
				this->y = this->y / mag;
			}
			else
			{
				this->x = 0;
				this->y = 0;
			}
			return *this;
		}

		auto clamped() -> geo::vec2_t
		{
			auto angles = *this;

			if (angles.x < -180.00f)
				angles.x += 360.00f;
			if (angles.x > 180.00f)
				angles.x -= 360.00f;

			if (angles.y < -180.00f)
				angles.y += 360.00f;
			if (angles.y > 180.00f)
				angles.y -= 360.00f;

			if (angles.x > 89.00f && angles.x <= 180.00f)
				angles.x = 89.00f;

			return angles;
		}

		auto clear() -> void
		{
			this->x = 0.00f;
			this->y = 0.00f;
		}
	};

	class vec3_t
	{
	public:
		float x, y, z;

		vec3_t() { x = y = z = 0.00f; }

		vec3_t(float x, float y, float z) { this->x = x; this->y = y; this->z = z; }

		auto operator+(const geo::vec3_t& input) -> geo::vec3_t { return geo::vec3_t{ x + input.x, y + input.y, z + input.z }; }

		auto operator-(const geo::vec3_t& input) -> geo::vec3_t { return geo::vec3_t{ x - input.x, y - input.y, z - input.z }; }

		auto operator==(const geo::vec3_t& input) -> bool { return x == input.x && y == input.y && z == input.z; }

		auto operator>(const geo::vec3_t& input) -> bool { return x > input.x && y > input.y && z > input.z; }

		auto operator<(const geo::vec3_t& input) -> bool { return x < input.x && y < input.y && z < input.z; }

		auto operator-=(const geo::vec3_t& v) -> geo::vec3_t { x -= v.x; y -= v.y; z -= v.z; return *this; }

		auto operator/(const geo::vec3_t& input) -> geo::vec3_t { return geo::vec3_t{ x / input.x, y / input.y, z / input.z }; }

		auto operator*(const geo::vec3_t& input) -> geo::vec3_t { return geo::vec3_t{ x * input.x, y * input.y, z * input.z }; }

		auto operator+=(const geo::vec3_t& v) -> geo::vec3_t { x += v.x; y += v.y; z += v.z; return *this; }

		auto operator+(float input) -> geo::vec3_t { return geo::vec3_t{ x + input, y + input, z + input }; }

		auto operator-(float input) -> geo::vec3_t { return geo::vec3_t{ x - input, y - input, z - input }; }

		auto operator/(float input) -> geo::vec3_t { return geo::vec3_t{ x / input, y / input, z / input }; }

		auto operator/=(float input) -> geo::vec3_t { x /= input; y /= input; z /= input; return *this; }

		auto operator*=(float input) -> geo::vec3_t { x *= input; y *= input; z *= input; return *this; }

		auto operator*(float input) -> geo::vec3_t { return geo::vec3_t{ x * input, y * input, z * input }; }

		static auto zero() -> geo::vec3_t
		{
			return geo::vec3_t(0.00f, 0.00f, 0.00f);
		}

		static auto get_right() -> geo::vec3_t
		{
			return geo::vec3_t(1.00f, 0.00f, 0.00f);
		}

		static auto get_left() -> geo::vec3_t
		{
			return geo::vec3_t(-1.00f, 0.00f, 0.00f);
		}

		static auto get_forward() -> geo::vec3_t
		{
			return geo::vec3_t(0.00f, 0.00f, 1.00f);
		}

		static auto get_backward() -> geo::vec3_t
		{
			return geo::vec3_t(0.00f, 0.00f, -1.00f);
		}

		static auto get_up() -> geo::vec3_t
		{
			return geo::vec3_t(0.00f, 1.00f, 0.00f);
		}

		static auto get_down() -> geo::vec3_t
		{
			return geo::vec3_t(0.00f, -1.00f, 0.00f);
		}

		auto is_empty() -> bool
		{
			return this->x == 0.00f && this->y == 0.00f && this->z == 0.00f;
		}

		auto dot(geo::vec3_t input) -> float
		{
			return (x * input.x) + (y * input.y) + (z * input.z);
		}

		auto length_sqr() -> float
		{
			return (x * x) + (y * y) + (z * z);
		}

		auto length() -> float
		{
			return (float)sqrt(length_sqr());
		}

		auto distance(geo::vec3_t input) -> float
		{
			return (*this - input).length();
		}

		auto normalized() -> geo::vec3_t
		{
			auto length = this->length();
			return { this->x / length , this->y / length, this->z / length };
		}

		auto magnitude() -> float
		{
			return (float)std::sqrtf((double)(this->x * this->x + this->y * this->y + this->z * this->z));
		}

		auto normalize() -> geo::vec3_t
		{
			float mag = this->length();
			if (mag > 0.00001f)
			{
				this->x = this->x / mag;
				this->y = this->y / mag;
				this->z = this->z / mag;
			}
			else
			{
				this->x = 0;
				this->y = 0;
				this->z = 0;
			}
			return *this;
		}

		auto clear() -> void
		{
			this->x = 0.00f;
			this->y = 0.00f;
			this->z = 0.00f;
		}
	};

	class vec4_t
	{
	public:
		float x, y, z, w;

		vec4_t() { x = y = z = w = 0.00f; }

		vec4_t(float x, float y, float z, float w) { this->x = x; this->y = y; this->z = z; this->w = w; }

		auto operator+(const geo::vec4_t& input) -> geo::vec4_t { return geo::vec4_t{ x + input.x, y + input.y, z + input.z, w + input.w }; }

		auto operator-(const geo::vec4_t& input) -> geo::vec4_t { return geo::vec4_t{ x - input.x, y - input.y, z - input.z, w - input.w }; }

		auto operator==(const geo::vec4_t& input) -> bool { return x == input.x && y == input.y && z == input.z && w == input.w; }

		auto operator>(const geo::vec4_t& input) -> bool { return x > input.x && y > input.y && z > input.z && w > input.w; }

		auto operator<(const geo::vec4_t& input) -> bool { return x < input.x && y < input.y && z < input.z && w < input.w; }

		auto operator-=(const geo::vec4_t& v) -> geo::vec4_t { x -= v.x; y -= v.y; z -= v.z; w -= v.w; return *this; }

		auto operator/(const geo::vec4_t& input) -> geo::vec4_t { return geo::vec4_t{ x / input.x, y / input.y, z / input.z, w / input.w }; }

		auto operator*(const geo::vec4_t& input) -> geo::vec4_t { return geo::vec4_t{ x * input.x, y * input.y, z * input.z, w * input.w }; }

		auto operator+=(const geo::vec4_t& v) -> geo::vec4_t { x += v.x; y += v.y; z += v.z; w += v.w; return *this; }

		auto operator+(float input) -> geo::vec4_t { return geo::vec4_t{ x + input, y + input, z + input, w + input }; }

		auto operator-(float input) -> geo::vec4_t { return geo::vec4_t{ x - input, y - input, z - input, w - input }; }

		auto operator/(float input) -> geo::vec4_t { return geo::vec4_t{ x / input, y / input, z / input, w / input }; }

		auto operator/=(float input) -> geo::vec4_t { x /= input; y /= input; z /= input; w /= input; return *this; }

		auto operator*=(float input) -> geo::vec4_t { x *= input; y *= input; z *= input; w *= input; return *this; }

		auto operator*(float input) -> geo::vec4_t { return geo::vec4_t{ x * input, y * input, z * input, w * input }; }

		auto is_empty() -> bool
		{
			return this->x == 0.00f && this->y == 0.00f && this->z == 0.00f && this->w == 0.00f;
		}

		auto dot(geo::vec4_t input) -> float
		{
			return (x * input.x) + (y * input.y) + (z * input.z) + (w * input.w);
		}

		auto length_sqr() -> float
		{
			return (x * x) + (y * y) + (z * z) + (w * w);
		}

		auto length() -> float
		{
			return (float)sqrt(length_sqr());
		}

		auto distance(geo::vec4_t input) -> float
		{
			return (*this - input).length();
		}

		auto normalized() -> geo::vec4_t
		{
			auto length = this->length();
			return { this->x / length , this->y / length, this->z / length, this->w / length };
		}

		auto clear() -> void
		{
			this->x = 0.f;
			this->y = 0.f;
			this->z = 0.f;
			this->w = 0.f;
		}
	};

	class m_matrix
	{
	public:
		union
		{
			struct
			{
				float _11, _12, _13, _14;
				float _21, _22, _23, _24;
				float _31, _32, _33, _34;
				float _41, _42, _43, _44;
			};
			float m[4][4];
		};

		m_matrix()
			: m{ { 0, 0, 0, 0 },
				 { 0, 0, 0, 0 },
				 { 0, 0, 0, 0 },
				 { 0, 0, 0, 0 } }
		{ }

		m_matrix(const m_matrix&) = default;

		auto transpose() -> m_matrix
		{
			m_matrix m;

			for (int i = 0; i < 4; ++i)
			{
				for (int x = 0u; x < 4; ++x)
				{
					m.m[i][x] = this->m[x][i];
				}
			}

			return m;
		}

		auto multiply_point_3(geo::vec3_t& input, geo::vec3_t& output) -> bool
		{
			float w = input.x * m[3][0] + input.y * m[3][1] + input.z * m[3][2] + m[3][3];
			if (std::abs(w) <= 0.0000001f)
			{
				output = geo::vec3_t(0, 0, 0);
				return false;
			}

			output.x = (input.x * m[0][0] + input.y * m[0][1] + input.z * m[0][2] + m[0][3]) / w;
			output.y = (input.x * m[1][0] + input.y * m[1][1] + input.z * m[1][2] + m[1][3]) / w;
			output.z = (input.x * m[2][0] + input.y * m[2][1] + input.z * m[2][2] + m[2][3]) / w;

			return true;
		}

		float* operator[](std::size_t idx) { return m[idx]; }
		const float* operator[](std::size_t idx) const { return m[idx]; }
	};

	auto cos_tan_sin_line_h(float angle, float range, std::int32_t x, std::int32_t y, std::int32_t length) -> geo::vec2_t
	{
		const auto yaw = (angle + 45.00f) * (3.1415926535f / 180.00f);

		const auto view_cos = cos(yaw);
		const auto view_sin = sin(yaw);

		const auto x2 = range * (-view_cos) + range * view_sin;
		const auto y2 = range * (-view_cos) - range * view_sin;

		return { (float)(x + (std::int32_t)(x2 / range * (length))), (float)(y + (std::int32_t)(y2 / range * (length))) };
	}

	auto rotate_point(geo::vec3_t position, geo::vec3_t local, float distance, float angle, float size, float range) -> geo::vec2_t
	{
		const auto y = local.x - position.x;
		const auto x = local.z - position.z;

		const auto num = std::atan2(y, x) * 57.29578f - 270.00f - angle;

		return { (distance * std::cos(num * 0.0174532924f)) * (size / range) / 2.00f,
			(distance * std::sin(num * 0.0174532924f)) * (size / range) / 2.00f };
	}

	auto calculate_bullet_drop(float height, float distance, float velocity, float gravity) -> float
	{
		float pitch = atan2(height, distance);
		float bullet_velocity = velocity * cos(pitch);
		float time = distance / bullet_velocity;

		return (0.525f * gravity * time * time) * 10;
	}

	auto to_rad(double degree) -> double
	{
		double pi = 3.14159265359;
		return (degree * (pi / 180));
	}

	auto to_quat(geo::vec3_t Euler) -> geo::vec4_t
	{
		double heading = to_rad(Euler.x);
		double attitude = to_rad(Euler.y);
		double bank = to_rad(Euler.z);

		double c1 = cos(heading / 2);
		double s1 = sin(heading / 2);
		double c2 = cos(attitude / 2);
		double s2 = sin(attitude / 2);
		double c3 = cos(bank / 2);
		double s3 = sin(bank / 2);
		double c1c2 = c1 * c2;
		double s1s2 = s1 * s2;
		geo::vec4_t quat;
		quat.w = c1c2 * c3 - s1s2 * s3;
		quat.x = c1c2 * s3 + s1s2 * c3;
		quat.y = s1 * c2 * c3 + c1 * s2 * s3;
		quat.z = c1 * s2 * c3 - s1 * c2 * s3;
		return { quat.y, quat.z, (quat.x * -1), quat.w };
	}

	auto to_quaternion(geo::vec2_t euler) -> geo::vec4_t
	{
		const auto to_radians = [&](float degree) -> double
			{
				return (degree * (M_PI / 180.f));
			};

		float heading = to_radians(euler.x);
		float attitude = to_radians(euler.y);
		float bank = to_radians(0);

		float c1 = std::cos(heading / 2);
		float s1 = std::sin(heading / 2);
		float c2 = std::cos(attitude / 2);
		float s2 = std::sin(attitude / 2);
		float c3 = std::cos(bank / 2);
		float s3 = std::sin(bank / 2);

		float c1c2 = c1 * c2;
		float s1s2 = s1 * s2;
		auto quat = geo::vec4_t(c1c2 * s3 + s1s2 * c3, s1 * c2 * c3 + c1 * s2 * s3, c1 * s2 * c3 - s1 * c2 * s3, c1c2 * c3 - s1s2 * s3);

		return { quat.y, quat.z, (quat.x * -1), quat.w };
	}

	auto quaternion_multi(const geo::vec3_t point, geo::vec4_t* quat) -> geo::vec3_t
	{
		float num = quat->x * 2.f;
		float num2 = quat->y * 2.f;
		float num3 = quat->z * 2.f;
		float num4 = quat->x * num;
		float num5 = quat->y * num2;
		float num6 = quat->z * num3;
		float num7 = quat->x * num2;
		float num8 = quat->x * num3;
		float num9 = quat->y * num3;
		float num10 = quat->w * num;
		float num11 = quat->w * num2;
		float num12 = quat->w * num3;
		geo::vec3_t result{};
		result.x = (1.f - (num5 + num6)) * point.x + (num7 - num12) * point.y + (num8 + num11) * point.z;
		result.y = (num7 + num12) * point.x + (1.f - (num4 + num6)) * point.y + (num9 - num10) * point.z;
		result.z = (num8 - num11) * point.x + (num9 + num10) * point.y + (1.f - (num4 + num5)) * point.z;
		return result;
	}

	struct c_tracers
	{
		geo::vec3_t bullet_pos;
		geo::vec3_t local_pos;
		std::chrono::time_point<std::chrono::steady_clock> shot_at;
	};
	std::vector<c_tracers> bullet_tracer;

	auto random_float(float a, float b) -> float
	{
		float random = ((float)rand()) / (float)RAND_MAX;
		float diff = b - a;
		float r = random * diff;
		return a + r;
	}

	auto calc_3d_dist(const geo::vec3_t& Src, const geo::vec3_t& Dst) -> float
	{
		return sqrt(power_max((Src.x - Dst.x)) + power_max((Src.y - Dst.y)) + power_max((Src.z - Dst.z)));
	}

	auto calculate_angle(geo::vec3_t src, geo::vec3_t dst) -> geo::vec2_t
	{
		auto direction = src - dst;

		return
		{
			(std::asinf(direction.y / direction.length()) * 57.295779513082321600f),
			(-std::atan2f(direction.x, -direction.z) * 57.295779513082321600f)
		};
	}

	auto clamp_float(float value) -> float
	{
		float result;
		if (value < 0.f)
		{
			result = 0.f;
		}
		else if (value > 1.f)
		{
			result = 1.f;
		}
		else
		{
			result = value;
		}
		return result;
	}

	auto lerp_vector(geo::vec3_t in) -> float
	{
		return in.x + (in.y - in.x) * clamp_float(in.z);
	}

	auto unity_calculate_angle(geo::vec3_t& src, geo::vec3_t& dst) -> geo::vec2_t
	{
		geo::vec3_t dir = src - dst;

		const auto sqrtss = [](float in)
			{ // thx can
				__m128 reg = _mm_load_ss(&in);
				return _mm_mul_ss(reg, _mm_rsqrt_ss(reg)).m128_f32[0];
			};

		float hyp = sqrtss(dir.x * dir.x + dir.y * dir.y + dir.z * dir.z);
		float nigga = std::roundf(dir.y);

		if (std::isnan(hyp))
			hyp = sqrtss(dir.x * dir.x + nigga * nigga);

		double ax = std::asin(dir.y / hyp);
		double ay = -std::atan2(dir.x, -dir.z);

		double x = RAD2DEG(ax);
		double y = RAD2DEG(ay);

		return vec2_t(static_cast<float>(x), static_cast<float>(y));
	}

	auto calc_3d_dist_vec2(geo::vec3_t src, geo::vec3_t dst) -> geo::vec2_t
	{
		geo::vec3_t dir = src - dst;
		return geo::vec2_t{ RAD2DEG(asin(dir.y / dir.length())), RAD2DEG(-atan2(dir.x, -dir.z)) };
	}

	auto magnitude_2d(const geo::vec3_t& v) -> float
	{
		return std::sqrt(v.x * v.x + v.y * v.y);
	}

	auto normalize(geo::vec2_t angles) -> geo::vec2_t
	{
		if (angles.x < -89) angles.x = -89;
		else if (angles.x > 89) angles.x = 89;
		if (angles.y < -360) angles.y += 360;
		else if (angles.y > 360) angles.y -= 360;

		return angles;
	}
	class c_reload_bar
	{
	public:
		float m_reload_time = 0.f;
		float m_reload_duration = 0.f;
	}; inline c_reload_bar reload_indicator;
}