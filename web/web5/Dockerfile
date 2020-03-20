from php:7.0-apache

run mkdir /var/www/html/cgi-bin
copy .htaccess /var/www/html
copy index.html /var/www/html
copy myscript /var/www/html/cgi-bin

run service apache2 start && echo "<Directory /var/www/html>" >> /etc/apache2/sites-available/000-default.conf && \
  echo "Options Indexes FollowSymLinks" >> /etc/apache2/sites-available/000-default.conf && \
  echo "AllowOverride All" >> /etc/apache2/sites-available/000-default.conf && \
  echo "Require all granted" >> /etc/apache2/sites-available/000-default.conf && \
  echo "</Directory>" >> /etc/apache2/sites-available/000-default.conf && \
  echo "ScriptAlias \"/cgi-bin/\" \"/var/www/html/cgi-bin/\"" >> /etc/apache2/sites-available/000-default.conf && \
  a2enmod rewrite && service apache2 restart && chmod 755 /var/www/html && chmod 755 /var/www/html/*
run chmod +x /var/www/html/cgi-bin/*
expose 80
