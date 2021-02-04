#include "PID.h"
#include <numeric>

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() :
  p_error(0.0)
  ,i_error(0.0)
  ,d_error(0.0)
  ,Kp(0.0)
  ,Ki(0.0)
  ,Kd(0.0)
{}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */

  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
}

void PID::Init(double p[]) {
  //Internal usage only
  Kp = p[0];
  Ki = p[1];
  Kd = p[2];
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  d_error = cte - p_error;
  p_error = cte;
  i_error += cte;
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  return -Kp * p_error - Ki * i_error - Kd * d_error;  // TODO: Add your total error calc here!
}

double PID::twiddle(double tolerance, double cte)
{
  double p[3] = {Kp, Ki, Kd};
  double dp[3] = {.05 * Kp, .05 * Ki, .05 * Kd};

  UpdateError(cte);
  auto bestError = TotalError();

  while (std::accumulate(dp, dp + 3, 0) > tolerance)
  //for (int it = 0; it < 100; ++it)
  {
    for (int i = 0; i < 3; ++i)
    {
      p[i] += dp[i];

      auto error = cte * cte;
      if (error < bestError)
      {
        bestError = error;
        dp[i] *= 1.1;
      }
      else
      {
        p[i] -= -2 * dp[i];

        if (error < bestError)
        {
          bestError = error;
          dp[i] *= 1.1;
        }
        else
        {
          p[i] += dp[i];
          dp[i] *= .9;
        }
      }
    }
  }

  Init(p);
  return TotalError();
}