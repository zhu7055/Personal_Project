SELECT eu.unique_id as unique_id,e.name as name
FROM  Employees e left join EmployeeUNI eu on e.id=eu.id