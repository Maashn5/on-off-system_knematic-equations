# on-off-system_knematic-equations
## on off system 
in on off systems by using a push button, with a single change (on or off) with every push 
<br/> with keeping the new state when release the button
<br/> The flipflop sounds the perfect solution, precisouly the T flipflop
<br/> The T flipflop change the output state when the toggle is high , and keep it when the toggle is low 
<br/> T flipflop truth table : 
<br/>![alt text](https://www.allaboutcircuits.com/uploads/articles/TB_TFF_3.JPG)
<br/> Since tinkercad doesn't support T-flipflop, we will use the j-k flipflop
<br/> J-K truth table :
<br/> ![alt text](https://i.stack.imgur.com/dBc8x.gif)
<br/> From the J-K truth table, we can convert J-K flipflop to T flipflop 
<br/> by shorted the J & K inputs to be one input represent the T input 
<br/> For the clock pin the flipflop will not work unless it detect a rising edge from the clock pin 
<br/> ![alt text](https://electricalnotebook.com/wp-content/uploads/2022/05/image-49.png)
<br/> Since the flipflop need a rising edge to activate the clock ,so we need a clock signal to activate the clock pin,
<br/> So we need to 555 timer or oscliation signal.
<br/> there is an alternative solution, since we need a rising edge in the clock to activate the flipflop
<br/> Otherwise nothing will happen , so if we keep the T input (j,k input) always high
<br/> And connect the push button to the clock ,so when the push button is pressed the rising edge will activate the
<br/> clock pin & the flipflop ,since the T is always high this will change the state of the output.
<br/> The reset pin we will keep it high so there will be no resets.
<br/> When the output is high this will activate the nmos transistor, thus the relay will be activated,   
<br/> thus the load will be activated too , there is a diode connected in parallel & reverse connection 
<br/> to protect the relay from reverse current.
<br/> Here is the circuit
<br/> ![alt text](https://github.com/Maashn5/on-off-system_knematic-equations/blob/main/on%20off%20system.png)
<br/> [Here is the simulation link for the circuit](https://www.tinkercad.com/things/h2Qnr8GqlwS?sharecode=uJGjH094gYhzXHnRIB97MQHVZjRLOgiVTZa7BDeb5bo)
## knematic equation
