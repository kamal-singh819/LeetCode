## self join method -1
# select 
#     case
#         when count(distinct salary) < 2 then NULL
#         else (
#              select distinct e1.salary from Employee as e1
#                 where 1 = (
#                     select count(distinct salary) from Employee as e2 
#                     where e2.salary > e1.salary
#                 )
#             )
#         end as SecondHighestSalary
#     from Employee;
    
## using max() aggrigate 
# select 
#     case
#         when count(distinct salary) < 2 then null
#         else (
#             select max(salary) from Employee where salary < (
#                 select max(salary) from Employee
#             )
#         )
#     end as SecondHighestSalary
# from Employee;

## using limit
# select
#     case
#         when count(distinct salary) < 2 then null
#         else (
#             select salary from Employee where salary < (
#                 select max(salary) from Employee
#             ) order by salary desc limit 1
#         )
#     end as SecondHighestSalary
# from Employee;

## using NOT IN or <> operator
select 
    case
        when count(distinct salary) < 2 then null
        else (
            select max(salary) from Employee where salary NOT IN (
                select max(salary) from Employee
            )
        )
    end as SecondHighestSalary
from Employee;


