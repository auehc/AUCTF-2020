from php:7.0-apache


run service apache2 start && mkdir /var/www/html/hidden/ && mkdir /var/www/html/api/ && \
  echo "<Directory /var/www/html>" >> /etc/apache2/sites-available/000-default.conf && \
  echo "Options Indexes FollowSymLinks" >> /etc/apache2/sites-available/000-default.conf && \
  echo "AllowOverride All" >> /etc/apache2/sites-available/000-default.conf && \
  echo "Require all granted" >> /etc/apache2/sites-available/000-default.conf && \
  echo "</Directory>" >> /etc/apache2/sites-available/000-default.conf && \
  a2enmod rewrite && service apache2 restart && chmod 755 /var/www/html && chmod 755 /var/www/html/*

copy index.html /var/www/html
copy authentication.js /var/www/html
copy nextstep.php /var/www/html/hidden
copy final.php /var/www/html/api
expose 80
