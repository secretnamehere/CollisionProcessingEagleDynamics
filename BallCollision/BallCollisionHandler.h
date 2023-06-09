#pragma once

#include "Ball.h"

namespace sf {
  class RenderWindow;
}

class BallCollisionAxisComparator
{
public:
  BallCollisionAxisComparator() = default;
  void SetComparisonAxisIdx(unsigned int iIdx);
  bool HasProjectionsIntersection(const Ball& iFirst, const Ball& iSecond);
  bool operator() (const Ball& iFirst, const Ball& iSecond);

private:
  unsigned int _comparisonAxisIdx{ 0u };
};

class BallCollisionHandler 
{
public:
  explicit BallCollisionHandler(sf::RenderWindow* ipWindow);
  void Process(std::vector<Ball>& iaBalls); //Sweep and Prune based
  void ProcessNaive(std::vector<Ball>& iaBalls); //for testing

private:
  void HandleCollision(Ball& iFirst, Ball& iSecond);
  void HandleWindowCollision(Ball& iBall);
  void DevideBalls(Ball& iFirst, Ball& iSecond, float iCentersDst, const sf::Vector2f& iNormal);
  void HitBalls(Ball& iFirst, Ball& iSecond, float iCentersDst, const sf::Vector2f& iNormal);

private:
  sf::RenderWindow* _pWindow{ nullptr };
  BallCollisionAxisComparator _comparator;

  static constexpr float _tolerance{ 1.f };
};