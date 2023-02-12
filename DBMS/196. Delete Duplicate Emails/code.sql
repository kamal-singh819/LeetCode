# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below


#temp1 and temp2 are temporary name of Person table
delete temp1 from Person temp1 inner join Person temp2 where temp1.email = temp2.email && temp1.id > temp2.id;
