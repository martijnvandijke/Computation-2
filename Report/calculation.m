     %Ref - clipping - changing the path - divison - forwarding , combined
     Cycles = [2350122, 2315926 , 2108766 , 1936494,  522695, 439280  ];
    Freq = [56.625, 56.471 , 56.625,  53.147, 56.552, 42.882  ];

%Cycles = [2350122, 2315926, 2108766, 1936494 , 522695, 2040848  ];
%Freq = [56.625,56.625 ,56.625, 56.465 , 56.465, 56.625 ];
Freq = Freq .* 10^6;

T = Cycles ./ Freq ;

%G = (T - T) ./ T; 

for i = 1 : size(T)
    disp(i)
         %if(i <4  )
%             i= i+1
%         else
%             b = i 
            G(i) = (( 0.041503258278146 - T(i)  ) ./ ( 0.041503258278146 )) .* 100;
            
            
        %end
      
end
close all;
figure();
somenames = {'Reference output','Hardware clipping instruction','Changing the critical path', 'Forwarding' ,'Hardware division', 'Combined ' };
barh(Cycles);
xlabel('Number of cycles');
set(gca,'yticklabel',somenames);
figure();
barh(T);
xlabel('Excution time [s] ');
set(gca,'yticklabel',somenames);
