     %Ref - clipping - lcc - forwarding - division
Cycles = [2350122, 2315926, 2108766,  496593 ];
Freq = [56.625,56.625 ,56.626, 56.387 ];
Freq = Freq .* 10^6;

T = Cycles ./ Freq ;

%G = (T - T) ./ T; 

for i = 1 : size(T)
         %if(i <4  )
%             i= i+1
%         else
%             b = i 
            G(i) = ( 0.041503258278146 - T(i)  ) ./ ( 0.041503258278146 ) .* 100;
            
            
        %end
      
end
%G = T