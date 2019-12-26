i=-1
while (( i++ < 5000 )); do
  cp ./foo.pdf "./foo$i.pdf"
done
