I=imread('t.jpg');
I3=I(:,:,3);

for a1= 1:100
    for a2= 1:100
        if I3(a1,a2)<=100
           I3(a1,a2)= 0 ;
        end
        if I3(a1,a2)>=100
           I3(a1,a2)= 255 ;
        end

    end
end    
I3
fid=fopen('output.txt','w');  
fprintf(fid,'%d\r\t,',I3);
fclose(fid);
