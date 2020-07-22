## Compiler Project ----------------------------------------------------------

Checkpoint #8 / Fully Implemented Compiler 

## Functionalities Successfully Implemented ----------------------------------- 

Assignment Statement
If Statement
If-Else Statement
While Loop
Print Statement
Read Statement
Exit Statement 
Counting Upward Loop
Counting Downward Loop

## Deficiencies ---------------------------------------------------------------

Counting Loops cannot check for contradictory values:
e.g. "counting var upward 5 to 5;" would make the loop go once and stop. 
     "counting var upward 10 to 5;" would simply not run the body of the loop. 

## Counting Loops -------------------------------------------------------------

Value of ending expression cannot be modified once the counting loop is declared. 
Control variable must be of INTEGER type. 

## Mod Operator ---------------------------------------------------------------

Two operands must be both INTEGERs (as required on the SLIC specifications). 
Non-integer operands are coerced into integers via truncation. 
Result produced is an integer. 

## Example SLIC programs tested and successfully computed --------------------- 

calendar_without_mod.slic 
calendar_with_mod.slic
peevedpigeons.slic
factorial.slic
blastoff.slic
euclid.slic 
zeller.slic
root.slic 
sine.slic
sort.slic



