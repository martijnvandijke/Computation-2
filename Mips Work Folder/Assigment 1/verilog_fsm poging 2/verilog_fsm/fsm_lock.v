`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: Tu/e
// Engineer: Martyn van Dijke
// 
// Create Date:    02/16/2016 
// Design Name: 		Tu/e
// Module Name:    fsm_lock 
// Project Name:	Finite State Machine -> assigment 1
//////////////////////////////////////////////////////////////////////////////////
module fsm_lock(
    input clk,
    input reset_in,
    input b0_in,
    input b1_in,
	 output reg out,
    output reg hex_display
    );

//variable declarition
localparam STATE_Initial = 3'd0,
	STATE_1 = 3'd1,
	STATE_2 = 3'd2,
	STATE_3 = 3'd3,
	STATE_4 = 3'd4,
	STATE_5 = 3'd5;

//register declaration's
reg [4:0] CurrentState;reg [4:0] NextState;

//for the reset function
always@(posedge clk	)begin
	if(Reset)
		NextState = STATE_Initial;
end

$display("The value of the display is: %d", hex_display) ;
always@(posedge clk	)begin
	NextState = CurrentState ;	
	case(CurrentState)
		STATE_Initial: begin
			hex_display = 0;
			out = 0;
			if(b0_in)
				NextState = STATE_1;
			if(b1_in)
				NextState= State_Initial;
			
		end
		STATE_1: begin
			hex_display = 1;
			out = 0;
			if(b1_in)
				NextState = STATE_2;
			
			if (b0_in)  
				NextState = STATE_1;
		
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
			if (b0_in == 0)  
				NextState = STATE_4;
			
			if (b1_in)
				NextState = STATE_Initial;
			
		end
		STATE_4: begin
			hex_display = 4;
			out = 0;
			if (b1_in)
				NextState = STATE_4;
			
			if (b0_in) 
				NextState = STATE_1;
				
			
		end	
		STATE_5: begin
			hex_display = 5;
			if (b1_in)
				out = 1;
				NextState = STATE_Initial;
				
			if (b0_in)
				out = 0;
				NextState = STATE_1;
				
			
		end
	endcase
end

endmodule 