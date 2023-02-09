# Write your MySQL query statement below

#create duplicate of employee as e1 and e2


select e2.name AS Employee from employee e1 INNER JOIN employee e2 ON e1.id = e2.managerId WHERE e1.salary < e2.salary;
