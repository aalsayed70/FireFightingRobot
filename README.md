# Big picture 
The Automated Firefighting miniCar with Bluetooth Control is a project aimed at developing a versatile firefighting vehicle capable of autonomously detecting and extinguishing fires.

# components 

The project incorporates multiple sensors, including a fire sensor and distance sensors. It also includes essential components such as a tank and pump for fire extinguishment, a servo and Bluetooth sensor for manual control, and motors for wheel movement. The code for this project is developed using the Arduino IDE

# working 

When the fire sensor detects the presence of fire, the firefighting car initiates a series of actions to automatically orient itself towards the fire and approach it for extinguishing. Here's a high-level overview of the process:
\begin{itemize}
\item Fire Detection: The fire sensor continuously monitors the surroundings for signs of fire, such as heat or smoke.

\item Orientation and Navigation: Once fire is detected, the car's algorithm determines the location of the fire source and calculates the appropriate orientation to face the fire.

\item Movement Towards the Fire: The motors controlling the wheels are activated to move the car towards the fire. The distance sensors help ensure safe navigation and obstacle avoidance during the approach.

\item Fire Suppression: As the car reaches the vicinity of the fire, the water pump connected to the tank is activated to spray water or other extinguishing agents onto the fire source. The aim is to suffocate the fire and reduce its intensity.
\end{itemize}
Monitoring and Feedback: Throughout the firefighting process, the car's sensors provide continuous feedback, allowing the system to adjust its approach and extinguishing techniques as necessary. This feedback loop ensures efficient and effective fire suppression. 

