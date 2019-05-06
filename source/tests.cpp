#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"
#include "color.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

TEST_CASE("Vektor Initialisierung")
{
  Vec2 a;
  REQUIRE(a.x == 0.0f);
  REQUIRE(a.y == 0.0f);
}

TEST_CASE("Vektor-Addition")
{
  Vec2 a{2.5f, 3.1f};
  Vec2 b{-1.5f, 6.7f};

  a += b;
  REQUIRE(a.x == Approx(1.0f)); 
  REQUIRE(a.y == Approx(9.8f));
  
}

TEST_CASE("Vektor-Addition 2")
{
  Vec2 a{2.5f, 3.1f};
  Vec2 b{-1.5f, 6.7f};
  Vec2 c;

  c = a + b;

  REQUIRE(c.x == Approx(1.0f));
  REQUIRE(c.y == Approx(9.8f));
}

TEST_CASE("Vektor-Subtraktion")
{
  Vec2 a{2.5f, 3.1f};
  Vec2 b{1.5f, -6.7f};

  a -= b;
  REQUIRE(a.x == Approx(1.0f)); 
  REQUIRE(a.y == Approx(9.8f));
}

TEST_CASE("Vektor-Subtraktion 2")
{
  Vec2 a{2.5f, 3.1f};
  Vec2 b{1.5f, -6.7f};
  Vec2 c;

  c = a - b;

  REQUIRE(c.x == Approx(1.0f));
  REQUIRE(c.y == Approx(9.8f));
}

TEST_CASE("Skalar-Multiplikation")
{
  Vec2 a{2.5f, 3.1f};
  Vec2 b{2.5f, 0.0f};

  a *= 2;
  b *= -2;
  REQUIRE(a.x == Approx(5.0f)); 
  REQUIRE(a.y == Approx(6.2f));
  REQUIRE(b.x == -5.0f);
  REQUIRE(b.y == Approx(0));
}

TEST_CASE("Skalar-Multiplikation 2")
{
  Vec2 a{2.5f, 3.1f};
  Vec2 b;

  b = a * 2;
  REQUIRE(b.x == Approx(5.0f)); 
  REQUIRE(b.y == Approx(6.2f));
}

TEST_CASE("Skalar-Division")
{
  Vec2 a{2.5f, -3.1f};

  a /= 2;
  REQUIRE(a.x == Approx(1.25f)); 
  REQUIRE(a.y == Approx(-1.55f));
}

TEST_CASE("Skalar-Division 2")
{
  Vec2 a{2.5f, 3.1f};
  Vec2 b;

  b = a / 2;
  REQUIRE(b.x == Approx(1.25f)); 
  REQUIRE(b.y == Approx(1.55f));
}

TEST_CASE("Matrizen Multiplikation")
{
  Mat2 a{3.0f, 2.5f, 1.5f, 0.4f};
  Mat2 b;

  a *= b;
  REQUIRE(a.e_00 == Approx(3.0f));
  REQUIRE(a.e_01 == Approx(2.5f));
  REQUIRE(a.e_10 == Approx(1.5f));
  REQUIRE(a.e_11 == Approx(0.4f));
}

TEST_CASE("Matrizen Multiplikation 2")
{
  Mat2 a{3.0f, 2.5f, 1.5f, 0.4f};
  Mat2 b;
  Mat2 c;

  c = a * b;
  REQUIRE(c.e_00 == Approx(3.0f));
  REQUIRE(c.e_01 == Approx(2.5f));
  REQUIRE(c.e_10 == Approx(1.5f));
  REQUIRE(c.e_11 == Approx(0.4f));
}

TEST_CASE("Vektor-Matrix Multiplikation")
{
  Mat2 m{3.0f, 2.5f, 1.5f, 0.4f};
  Vec2 v{4.0f, 2.0f};
  Vec2 erg;

  erg = m * v;
  REQUIRE(erg.x == Approx(17.0f));
  REQUIRE(erg.y == Approx(6.8f));

  erg = v * m;
  REQUIRE(erg.x == Approx(17.0f));
  REQUIRE(erg.y == Approx(6.8f));
}

TEST_CASE("Determinate")
{
  Mat2 m{3.0f, -2.5f, 1.5f, 0.4f};

  float det;
  det = m.det();
  REQUIRE(det == Approx(4.95f));
}

TEST_CASE("Inverses einer Matrix")
{
  Mat2 m{3.0f, -2.5f, 1.5f, 0.4f};

  Mat2 erg;
  erg = inverse(m);

  REQUIRE(erg.e_00 == Approx(0.08081f));
  REQUIRE(erg.e_01 == Approx(0.50505f));
  REQUIRE(erg.e_10 == Approx(-0.30303f));
  REQUIRE(erg.e_11 == Approx(0.60606f));
}
  

TEST_CASE("Transponierte Matrix")
{
  Mat2 m{3.0f, 2.5f, -1.5f, 0.4f};
  Mat2 erg;

  erg = transpose(m);
  REQUIRE(erg.e_00 == m.e_00);
  REQUIRE(erg.e_01 == m.e_10);
  REQUIRE(erg.e_10 == m.e_01);
  REQUIRE(erg.e_11 == m.e_11);
}

TEST_CASE("Rotationsmatrix")
{
  float rot = 30.0f;
  float rot2 = -30.0f;
  Mat2 erg;
  Mat2 erg2;

  erg = make_rotation_mat2(rot);
  REQUIRE(erg.e_00 == Approx(0.15425f));
  REQUIRE(erg.e_01 == Approx(0.98803f));
  REQUIRE(erg.e_10 == Approx(-0.98803f));
  REQUIRE(erg.e_11 == Approx(0.15425f));

  erg2 = make_rotation_mat2(rot2);
  REQUIRE(erg2.e_00 == 1);
  REQUIRE(erg2.e_01 == 0);
  REQUIRE(erg2.e_10 == 0);
  REQUIRE(erg2.e_11 == 1);
}

TEST_CASE("Schönes Stein-Grau")
{
  Color grau;

  REQUIRE(grau.r == 0.5f);
  REQUIRE(grau.g == 0.5f);
  REQUIRE(grau.b == 0.5f);
}

TEST_CASE("Rechteck Umfang")
{
  Vec2 min{3.0f, -2.0f};
  Vec2 max{5.0f, 5.0f};
  Color color{0.3, 0.5, 0.1};
  Rectangle rect{min, max, color};
  float circumference_;
  
  circumference_ = rect.circumference();
  
  REQUIRE(circumference_ == Approx(18.0f));
}

TEST_CASE("Kreis Umfang")
{
  Vec2 center{0.0f, 0.0f};
  Color color;
  Circle kreis{center, 4, color};
  float circumference_;

  circumference_ = kreis.circumference();

  REQUIRE(circumference_ == Approx(25.132741229f));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
