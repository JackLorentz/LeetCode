# Read from the file file.txt and output the tenth line to stdout.
:<<!
# (多行註解)
# 法1
i=1
#讀檔方式: IFS= read -r 同行欄位1 同行欄位2 ...
while IFS= read -r line ; do
   if [ $i = 10 ] ; then
        echo "$line"
        break
   fi
   i=$(($i+1))
done < file.txt
!
# 法2
# sed: 當有需要進行字串取代、複製、刪除的功能，sed 指令是最佳的處理工具。
sed -n 10p file.txt