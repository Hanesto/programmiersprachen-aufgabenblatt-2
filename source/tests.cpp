#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"

TEST_CASE("Vektor Initialisierung")
{
  Vec2 a;
  REQUIRE(a.x == 0.0f);
  REQUIRE(a.y == 0.0f);
}

TEST_CASE("Vektor-Addition")
{
  Vec2 a{2.5f, 3.1f};
  Vec2 b{1.5f, 6.7f};

  a += b;
  REQUIRE(a.x == Approx(4.0f)); 
  REQUIRE(a.y == Approx(10.7f));
  
}

TEST_CASE("Vektor-Addition 2")
{
  Vec2 a{2.5f, 3.1f};
  Vec2 b{1.5f, 6.7f};
  Vec2 c;

  c = a + b;

  REQUIRE(c.x == Approx(4.0f));
  REQUIRE(c.y == Approx(10.7f));
}

TEST_CASE("Vektor-Subtraktion")
{
  Vec2 a{2.5f, 3.1f};
  Vec2 b{1.5f, 6.7f};

  a -= b;
  REQUIRE(a.x == Approx(1.0f)); 
  REQUIRE(a.y == Approx(-3.6f));
}

TEST_CASE("Vektor-Subtraktion 2")
{
  Vec2 a{2.5f, 3.1f};
  Vec2 b{1.5f, 6.7f};
  Vec2 c;

  c = a - b;

  REQUIRE(c.x == Approx(1.0f));
  REQUIRE(c.y == Approx(-3.6f));
}

TEST_CASE("Skalar-Multiplikation")
{
  Vec2 a{2.5f, 3.1f};

  a *= 2;
  REQUIRE(a.x == Approx(5.0f)); 
  REQUIRE(a.y == Approx(6.2f));
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
  Vec2 a{2.5f, 3.1f};

  a /= 2;
  REQUIRE(a.x == Approx(1.25f)); 
  REQUIRE(a.y == Approx(1.55f));
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
  REQUIRE(a.e_10 == Approx(4.0f));
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
  REQUIRE(c.e_10 == Approx(4.0f));
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
  REQUIRE(det == Approx(-2.55f));
}

TEST_CASE("Inverses einer Matrix")
{
  //funktioniert noch nicht
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
  Mat2 erg;

  erg = make_rotation_mat2(rot);
  REQUIRE(erg.e_00 == Approx(0.866f));
  REQUIRE(erg.e_00 == Approx(-0.5f));
  REQUIRE(erg.e_00 == Approx(0.5f));
  REQUIRE(erg.e_00 == Approx(0.866f));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
