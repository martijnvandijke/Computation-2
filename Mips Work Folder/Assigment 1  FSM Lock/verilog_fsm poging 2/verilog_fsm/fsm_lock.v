`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: Tu/e
// Name: 				Martyn van Dijke
// Student Number: 	0887668
// Create Date:    	02/16/2016 
// Design Name: 		Tu/e
// Module Name:    	fsm_lock 
// Project Name:		Finite State Machine -> assigment 1
//////////////////////////////////////////////////////////////////////////////////
module fsm_lock(
    input clk,
    input reset_in,
    input b0_in,
    input b1_in,
	 output out,
    output hex_display
    );

//variable declarition
localparam 
	STATE_Initial = 3'd0,
	STATE_1 = 3'd1,
	STATE_2 = 3'd2,
	STATE_3 = 3'd3,
	STATE_4 = 3'd4,
	STATE_5 = 3'd5;

//register declaration's
reg [3:0] CurrentState;reg [3:0] NextState;
reg [1:0]  out;
reg [3:0]  hex_display;

//intial declaration
initial begin
CurrentState = STATE_Initial;
NextState = STATE_Initial;
end
//first always block
always@(b0_in or b1_in or reset_in)begin
	if(reset_in)
		NextState = STATE_Initial;
	else
	
	//NextState = CurrentState ;	
	CurrentState = NextState;
	case(CurrentState)
		STATE_Initial: begin
			hex_display =0;
			out = 0;
			if(b0_in)
				NextState = STATE_1;
			
		end
		STATE_1: begin
			hex_display = 1;
			out = 0;
			if	(b1_in)
				NextState = STATE_2;

		
		end
		STATE_2: begin
			hex_display = 2;
			out = 0;
			if(b1_in)
				NextState = STATE_3;
			
			if (b0_in) 
				NextState = STATE_1;
			
		end
		STATE_3: begin
			hex_display = 3;
			out = 0;
			if (b0_in)  
				NextState = STATE_4;
			
			if (b1_in)
				NextState = STATE_Initial;
			
		end
		STATE_4: begin
			hex_display =4;
			out = 0;
			if (b1_in)
				NextState = STATE_5;
			
			if (b0_in) 
				NextState = STATE_1;
			
		end	
		STATE_5: begin
			out = 1;
			hex_display = 5;
			if (b1_in)
				NextState = STATE_Initial;
				
			if (b0_in)
				NextState = STATE_1;
				
			
		end
	endcase

	
end

//second always block
always@(posedge clk) begin
	CurrentState = NextState;
	end
	


endmodule 