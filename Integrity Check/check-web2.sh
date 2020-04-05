if curl -I -L -s -w "%{http_code}" http://challenges.auctf.com:30021/ | (! grep -q "200"); then
  cd ~/AUCTF-2020 && /bin/bash rebuild-web2.sh && echo -e `date`: Rebuilt because error.
else
  echo -e `date`: "Nothing to do"
fi
