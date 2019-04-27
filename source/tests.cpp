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
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
