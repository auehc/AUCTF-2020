from php:7.0-apache

copy secret/server/question.php /var/www/html

run service apache2 start && echo "<Directory /var/www/html>" >> /etc/apache2/sites-available/000-default.conf && \
  echo "Options Indexes FollowSymLinks" >> /etc/apache2/sites-available/000-default.conf && \
  echo "AllowOverride All" >> /etc/apache2/sites-available/000-default.conf && \
  echo "Require all granted" >> /etc/apache2/sites-available/000-default.conf && \
  echo "</Directory>" >> /etc/apache2/sites-available/000-default.conf && \
  a2enmod rewrite && service apache2 restart && chmod 755 /var/www/html && chmod 755 /var/www/html/*

expose 80
