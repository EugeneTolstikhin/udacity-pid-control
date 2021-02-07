# PID controller project

PID Controller helps the vehicle to keep the track with the defined path. It's a quite easy algorithm but the parameters need to be tuned properly.

I tried both approaches - manual tuning and twiddle. As a result I tuned all the coefficients manually. Twiddle showed no visible advantages in tuning.

The following configuration shows the best results in case of errors:
**Kp = 0.1**
**Ki = 0.0001**
**Kd = 2.0**
**error = [-0.5, 0.5]**
**throttle = 0.15**

I have tested different parameters with the different vehicle speed (*throttle* parameter), but the vehicle was able to go only 1 lap without driving off the road. Minimum during the second lap the vehicle drove off the road. But the mentioned parameters allow vehicle to pass 5-10 laps (different tests were made) without errors (driving off the road).

***Throttle = 0.15*** provides maximum speed 15 mph. That can be very slow for the car in the city or in the highway, but it is a good result for the vehicles like, hotels' shuttles, golf clubs' shuttles, airport interterminal shuttles, etc.

As a result, the PID algorithm with such parameters can be considered as a one of the successfull use case which works for sure.