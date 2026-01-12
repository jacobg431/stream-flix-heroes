
SELECT Name FROM Skill 
INNER JOIN HeroSkill HS 
ON Skill.Id = HS.SkillId
WHERE HS.HeroId = (SELECT Id FROM Hero WHERE Name = 'Gandalf');

SELECT Name FROM Hero
INNER JOIN HeroSkill HS
ON Hero.Id = HS.HeroId
WHERE HS.SkillId = (SELECT Id FROM Skill WHERE Name = 'Eagle taxi');