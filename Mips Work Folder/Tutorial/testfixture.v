// Verilog test fixture created from schematic C:\Users\martijn\Documents\GitHub\Computation-2\Mips Work Folder\fulladder.sch - Fri Feb 12 14:25:48 2016

`timescale 1ns / 1ps

module fulladder_fulladder_sch_tb();

// Inputs
   reg c;
   reg b;
   reg a;

// Output
   wire sum;
   wire carry;

// Bidirs

// Instantiate the UUT
   fulladder UUT (
		.c(c), 
		.b(b), 
		.a(a), 
		.sum(sum), 
		.carry(carry)
   );
// Initialize Inputs
   //`ifdef auto_init
       initial begin
		c = 0;
		b = 0;
		a = 0;
   end
always #50
begin
a = ~a;
end
always @(posedge a)
begin
b = ~b;
end
always @(posedge b)
begin
c = ~c;
end
endmodule
