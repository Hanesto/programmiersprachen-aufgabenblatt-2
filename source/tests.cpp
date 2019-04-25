#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"

TEST_CASE("Vektor-Addition")
{
  Vec2 a{2.5f, 3.1f};
  Vec2 b{1.5f, 6.7f};

  a += b;
  REQUIRE(a.x == Approx(4.0f)); 
  REQUIRE(a.y == Approx(9.8f));
  
}

TEST_CASE("Vektor-Subtraktion")
{
  Vec2 a{2.5f, 3.1f};
  Vec2 b{1.5f, 6.7f};

  a -= b;
  REQUIRE(a.x == Approx(1.0f)); 
  REQUIRE(a.y == Approx(-3.6f));
}

TEST_CASE("Skalar-Multiplikation")
{
  Vec2 a{2.5f, 3.1f};

  a *= 2;
  REQUIRE(a.x == Approx(5.0f)); 
  REQUIRE(a.y == Approx(6.2f));
}

TEST_CASE("Skalar-Division")
{
  Vec2 a{2.5f, 3.1f};

  a /= 2;
  REQUIRE(a.x == Approx(1.25f)); 
  REQUIRE(a.y == Approx(1.55f));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
