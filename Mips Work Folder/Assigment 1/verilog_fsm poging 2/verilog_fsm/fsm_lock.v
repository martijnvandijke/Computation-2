`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: Tu/e
// Engineer: Martyn van Dijke
// 
// Create Date:    02/16/2016 
// Design Name: 		Tu/e
// Module Name:    fsm_lock 
// Project Name: 
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module fsm_lock(
    input clk,
    input reset_in,
    input b0_in,
    input b1_in,
	 output reg out,
    output reg hex_display
    );

localparam STATE_Initial = 3'd0,
	STATE_1 = 3'd1,
	STATE_2 = 3'd2,
	STATE_3 = 3'd3,
	STATE_4 = 3'd4,
	STATE_5 = 3'd5;


reg [3:0] CurrentState;reg [3:0] NextState;

always@(posedge clk	)begin
	NextState = CurrentState ;
	//if(Reset)
		//NextState = STATE_Initial;
	//end
	
	case(CurrentState)
		STATE_Initial: begin
			if(b0_in)
				NextState = STATE_1;
			
		end
		STATE_1: begin
			if(b1_in)
				NextState = STATE_2;
			
			if (b0_in)  //0
				NextState = STATE_1;
			//end
		end
		STATE_2: begin
			if(b1_in)
				NextState = STATE_3;
			
			if (b0_in)  //0
				NextState = STATE_1;
			
		end
		STATE_3: begin
			if (b0_in == 0)  //0
				NextState = STATE_4;
			//end
			if (b1_in)
				NextState = STATE_Initial;
			
		end
		STATE_4: begin
			if (b1_in)
				NextState = STATE_4;
			
			if (b0_in) //0
				NextState = STATE_1;
				
			//end
		end	
		STATE_5: begin
			if (b1_in)
				out = 1;
				NextState = STATE_Initial;
			
			
			if (b0_in)	 //0
				NextState = STATE_1;
				
			//end
		end
	endcase
end

endmodule 