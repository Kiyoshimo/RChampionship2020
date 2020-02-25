I=imread('t.jpg')
I3=I(:,:,3)

for a1= 1:100
    for a2= 1:100
        if I3(a1,a2)<=100
           I3(a1,a2)= 0 
        elseif I3(a1,a2)>=200
           I3(a1,a2)= -1 
        end

    end
end    

fid=fopen('output.txt','w');                                %需要改文件名称的地方
fprintf(fid,' %f \n',I3);                          %data：需要导出的数据名称
fclose(fid);
