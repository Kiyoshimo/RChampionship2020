import serial #导入模块
SerOut = "NoData\n"

try:
  #串口设置---------------------------------------------------------------------
  portx="COM3"#端口
  bps=9600#波特率，标准值之一：50,75,110,134,150,200,300,600,1200,1800,2400,4800,9600,19200,38400,57600,115200
  timex=5 #超时设置,None：永远等待操作，0为立即返回请求结果，其他值为等待超时时间(单位为秒）
  ser=serial.Serial(portx,bps,timeout=timex)# 打开串口，并得到串口对象

  while(1):
    # 写数据
    # 输出格式（pin针数,x0,x1,x2_.......）
    SerOut = input("input:")#测试用
    #SerOut = "5,6,4,6,3,1\n"#测试用
    result=ser.write((SerOut+'\n').encode("gbk"))
    print("写总字节数:",result)

  ser.close()#关闭串口

except Exception as e:
    print("串口异常：",e)
