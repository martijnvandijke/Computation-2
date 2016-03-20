
Cycles = [2350122, 2315926, 2108766, 456685 ];
Freq = [56.625,56.625 ,56.626,56.387 ];
Freq = Freq .* 10^6;

T = Cycles ./ Freq ;

G = (T - T) ./ T; 

for i = 1 : 4
         if(i <4  )
%             i= i+1
%         else
%             b = i 
            G(i) = ( T(i ) - T(i +1)  ) ./ ( T(i) ) .* 100;
            
            
        end
      
end
%G = T