     %Ref - clipping -  divison
     Cycles = [2350122, 2315926 ,  522695 ];
    Freq = [56.625, 56.471 ,  53.147 ];

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
somenames = {'Reference output','Clip instruction','Changing the path', 'Forwarding' ,'Division', 'LCC optimizations ' };
barh(Cycles);
xlabel('Number of cycles');
set(gca,'yticklabel',somenames);
figure();
barh(T);
xlabel('Excution time [s] ');
set(gca,'yticklabel',somenames);
