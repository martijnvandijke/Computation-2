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
	//out_1 = 1'd1,
	//out_0 = 1'd0,
	//hex_display_0 = 3'd0,
	//hex_display_1 = 3'd1,
	//hex_display_2 = 3'd2,
	//hex_display_3 = 3'd3,
	//hex_display_4 = 3'd4,
	//hex_display_5 = 3'd5
	//;
	//hex_dispaly;

//register declaration's
reg [3:0] CurrentState;reg [3:0] NextState;
reg [1:0]  out;
reg [3:0]  hex_display;

//for the reset function
//always@(posedge clk	)begin
	///if(reset_in)
		//NextState = STATE_Initial;
//end


initial begin
CurrentState = STATE_Initial;
NextState = STATE_Initial;
end
always@(b0_in or b1_in or reset_in)begin
	if(reset_in)
		NextState = STATE_Initial;
	else
	
	//NextState = CurrentState ;	
	CurrentState = NextState;
	case(CurrentState)
		STATE_Initial: begin
			//hex_display = STATE_Initial;
			//hex_display = hex_display_0;
			hex_display =0;
			out = 0;
			if(b0_in)
				NextState = STATE_1;
			//if(b1_in)
				//NextState= STATE_Initial;
			
		end
		STATE_1: begin
			//hex_display = STATE_1;
			//hex_display = hex_display_1;
			hex_display = 1;
			out = 0;
			if	(b1_in)
				NextState = STATE_2;
			
			//if (b0_in)  
				//NextState = STATE_1;
		
		end
		STATE_2: begin
			//hex_display = STATE_2;
			//hex_display = hex_display_2;
			hex_display = 2;
			out = 0;
			if(b1_in)
				NextState = STATE_3;
			
			if (b0_in) 
				NextState = STATE_1;
			
		end
		STATE_3: begin
			//hex_display = STATE_3;
			//hex_display = hex_display_3;
			hex_display = 3;
			out = 0;
			if (b0_in)  
				NextState = STATE_4;
			
			if (b1_in)
				NextState = STATE_Initial;
			
		end
		STATE_4: begin
			//hex_display = STATE_4;
			//hex_display = hex_display_4;
			hex_display =4;
			out = 0;
			if (b1_in)
				NextState = STATE_5;
			
			if (b0_in) 
				NextState = STATE_1;
			
		end	
		STATE_5: begin
			//hex_display = STATE_5;
			//hex_display = hex_display_5;
			out = 1;
			hex_display = 5;
			if (b1_in)
				NextState = STATE_Initial;
				
			if (b0_in)
				NextState = STATE_1;
				
			
		end
	endcase
	

	//$display("The value of the state 1 is: %d", STATE_1);
	//$display("The value of the state 2 is: %d", STATE_2);
	//$display("The value of satte 3 is: %d", STATE_3);
	//$display("The value of state 4 is: %d", STATE_4);
	//$display("The value of state 5 is: %d", STATE_5);
	//$display("The value of state 0 is: %d", STATE_Initial);
	//$display("The value of the hex display is: %d", hex_display);
	//$display("The value of the output is: %d", out);
	//$display("The value of the output 0 is: %d", out_0);
	//$display("The value of the output 1 is: %d", out_1);
	//$display("The value of the hexdispaly 0 is: %d", hex_display_0);
	//$display("The value of the hexdisplay 1 is: %d", hex_display_1);
	//$display("The value of the hexdisplay 2 is: %d", hex_display_2);

	
end

always@(posedge clk) begin
	CurrentState = NextState;
	end
	


endmodule 