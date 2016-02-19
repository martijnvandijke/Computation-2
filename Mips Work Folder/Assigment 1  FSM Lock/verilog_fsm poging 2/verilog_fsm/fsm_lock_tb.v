`timescale 1ns / 1ps

module fsm_lock_tb;

	// Inputs
	reg clk;
	reg reset_in;
	reg b0_in;
	reg b1_in;

	// Outputs
	wire out;
	wire [3:0] hex_display;
	
	integer i;
	integer j;
	integer r;
	integer f;
	integer start;

	// Instantiate the Unit Under Test (UUT)
	fsm_lock uut (
		.clk(clk), 
		.reset_in(reset_in), 
		.b0_in(b0_in), 
		.b1_in(b1_in), 
		.out(out), 
		.hex_display(hex_display)
	);

	initial begin
		f = $fopen("trace.txt","w");
		// Initialize Inputs
		clk = 0;
		reset_in = 0;
		b0_in = 0;
		b1_in = 0;
		start = 0;
		
		#100
		reset_in = 1;
		#100
		reset_in = 0;
		start = 1;
		
		// Generate all codes
		for(i=0; i < 32; i=i+1) begin	
		   // Ensure resets from all states
			for(r=4; r >= 0; r=r-1) begin
				#100
				reset_in = 1;
				b0_in = 0;
				b1_in = 0;
				#100
				reset_in = 0;
				b0_in = 0;
				b1_in = 0;
			   // Press the buttons
				for (j=4; j>r; j=j-1) begin
					#100
					reset_in = 0;
					b0_in = 0;
					b1_in = 0;
					#100
					b0_in = ~i[j];
					b1_in = i[j];
				end
				#100
				reset_in = 1;
				b0_in = 0;
				b1_in = 0;
				for (j=r; j>=0; j=j-1) begin
					#100
					reset_in = 0;
					b0_in = 0;
					b1_in = 0;
					#100
					b0_in = ~i[j];
					b1_in = i[j];
				end
			end
  	   end
		#100
		$display("Completed input.");
		$fclose(f);
		f = 0;
		$finish;
	end
	
	always @ (out) begin
		if (out == 1) begin
			if (i == 13) begin
				$display("Correctly opens using %5b", i[4:0]);
			end else begin
				$display("ERROR! opens using %5b", i[4:0]);
				$finish;
			end
		end
	end
	
	always @(hex_display) begin
		if (start == 1 && f != 0) begin
			$fwrite(f,"%5b\t%1d\t%4b\t%b\n",i[4:0],r,hex_display,out);
		end
	end
	
	always begin
	   // Generate Clock
	   #50
		clk = ~clk;
	end
	   
endmodule

