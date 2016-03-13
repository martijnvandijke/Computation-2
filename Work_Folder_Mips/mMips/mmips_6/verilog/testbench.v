`timescale 1ns / 1ps
////////////////////////////////////////////////
// TESTBENCH.V
//
// TU/e Eindhoven University Of Technology
// Eindhoven, The Netherlands
// 
// Created: 21-11-2013
// Author: Bergmans, G (g.bergmans@student.tue.nl)
// Based on work by Sander Stuijk
// 
// Function:
//  Combines the mMIPS with simulated RAM, ROM and Device handler
//  for simulation purposes
//
// Version:
//     (27-01-2014): initial version
//
//////////////////////////////////////////////!/

`include "mmips_defines.v"

module testbench();
    
    reg clk, en, rst;
    
    integer f;
    integer l;
    
    integer cycles;
    integer clkgen;
    
    mMIPS_sim mMIPS_sim(
        .clk(clk),
        .en(en),
        .rst(rst)
    );
    
    //Reset and init
    initial begin
        clkgen = 0;
        cycles = 0;
        
        //Enable the system
        en = 1;
        #1
        
        //Reset the system
        rst = 1;
        clk = 0;
        #50 //Period/2
        clk = 1;
        #50 //Period/2
        rst = 0;
        clkgen = 1;
    end
    
    always begin
        if (clkgen == 1) begin
            clk = ~clk;
            cycles = clk ? cycles + 1 : cycles;
            #50
            if (mMIPS_sim.mMIPS.bus_pc == 32'h44) begin
                f = $fopen("../memory/ram/mips_ram.dump.hex","w");
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM00.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM01.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM02.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM03.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM04.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM05.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM06.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM07.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM08.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM09.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM10.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM11.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM12.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM13.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM14.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM15.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM16.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM17.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM18.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM19.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM20.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM21.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM22.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM23.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM24.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM25.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM26.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM27.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM28.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM29.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM30.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM31.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM32.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM33.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM34.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM35.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM36.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM37.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM38.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM39.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM40.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM41.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM42.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM43.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM44.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM45.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM46.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM47.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM48.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM49.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM50.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM51.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM52.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM53.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM54.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM55.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM56.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM57.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM58.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM59.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM60.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM61.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM62.mem[l][31-:32]); end
                for (l=0; l<512; l=l+1) begin $fwrite(f,"%08x\n",mMIPS_sim.dmem.BRAM63.mem[l][31-:32]); end
                $fclose(f);
                
                $display("Finished in %d cycles\n",cycles);
                $finish;
            end
        end
        else
            #1 cycles = 0;
    end

endmodule
