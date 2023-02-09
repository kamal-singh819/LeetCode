# Write your MySQL query statement below


select name as Customers from customers LEFT JOIN Orders ON customers.id = Orders.customerId WHERE Orders.id is NULL;
