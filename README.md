# on-off-system_knematic-equations
## on-off system 
In on-off systems by using a push button, every push will be on or off and keeping the new state when releasing the button.
<br/> The flipflop sounds like the perfect solution, and the T flipflop is the previous one.
<br/> The T flipflop changes the output state when the toggle is high and keeps it when the toggle is low.
<br/> T flip flop truth table: 
<br/>![alt text](https://www.allaboutcircuits.com/uploads/articles/TB_TFF_3.JPG)
<br/> Since Tinkercad doesn't support T-flipflop, we will use the j-k flipflop.
<br/> J-K truth table :
<br/> ![alt text](https://i.stack.imgur.com/dBc8x.gif)
<br/> From the J-K truth table, we can convert the J-K flipflop to a T flipflop by shorting the J & K inputs to be one input representing the T input.
<br/> For the clock pin, the flipflop will not work, unless it detects a rising edge from the clock pin. 
<br/> ![alt text](https://electricalnotebook.com/wp-content/uploads/2022/05/image-49.png)
<br/> Since the flipflop needs a rising edge to activate the clock, we need a clock signal to activate the clock pin,
<br/> and 555 timers or oscillation signals are needed.
<br/> There is an alternative solution since we need a rising edge in the clock to activate the flipflop.
<br/> Otherwise, nothing will happen.
<br/> So if we keep the T input (j,k input) always high
<br/> and connect the push button to the clock, when the push button is pressed, the rising edge will activate the
<br/> clock pin & the flipflop. Since the T is always high, this will change the state of the output.
<br/> The reset pin keeps high so there will be no resets.
<br/> When the output is high this will activate the nMOS transistor, thus the relay will be activated.   
<br/> Thus the load will be activated too.
<br/> There is a diode connected in parallel & reverse connection 
<br/> to protect the relay from reverse current.
<br/> Here is the circuit:
<br/> ![alt text](https://github.com/Maashn5/on-off-system_knematic-equations/blob/main/on%20off%20system.png)
## knematic equation
